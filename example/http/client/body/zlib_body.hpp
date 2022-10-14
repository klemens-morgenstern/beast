//
// Copyright (c) 2022 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BEAST_ZLIB_BODY_HPP
#define BEAST_ZLIB_BODY_HPP

#include <boost/beast/http/message.hpp>
#include <boost/beast/zlib.hpp>
#include "boost/beast/core/flat_buffer.hpp"

#include <iostream>

template<typename InnerBody>
struct zlib_body
{
    using value_type = typename InnerBody::value_type;

    struct reader
    {
        using inner_reader = typename InnerBody::reader;

        inner_reader ireader;
        boost::beast::zlib::inflate_stream inf;
        boost::beast::zlib::z_params zp;
        bool inflate  = false ;
        boost::beast::flat_buffer inner_buffer;

        template<bool isRequest, class Fields>
        explicit
        reader(boost::beast::http::header<isRequest, Fields>&h, value_type& b) : ireader(h, b)
        {
            auto itr = h.find(boost::beast::http::field::content_encoding);
            if (itr != h.end())
                inflate = boost::beast::iequals(itr->value(), "deflate");
        }

        void
        init(boost::optional<std::uint64_t> const& length,
             boost::system::error_code& ec)
        {
            if(length)
                inner_buffer.reserve(*length);
            ec = {};
        }

        template<class ConstBufferSequence>
        std::size_t
        put(ConstBufferSequence const& buffers,
            boost::system::error_code& ec)
        {
            if (!inflate)
                return ireader.put(buffers, ec);

            std::size_t consumed = 0u;
            for (auto itr  = boost::asio::buffer_sequence_begin(buffers);
                      itr != boost::asio::buffer_sequence_end(buffers);
                      itr++)
            {
                boost::asio::const_buffer cb = *itr;
                while (!ec && cb.size() > 0u)
                {
                    zp.data_type = boost::beast::zlib::kind::unknown;
                    zp.next_in = cb.data();
                    zp.total_in = 0u;
                    zp.avail_in = cb.size();
                    boost::asio::mutable_buffer mb = inner_buffer.prepare(boost::beast::zlib::deflate_upper_bound(cb.size()));
                    zp.next_out = mb.data();
                    zp.total_out = 0u;
                    zp.avail_out = mb.size();

                    inf.write(zp, boost::beast::zlib::Flush::sync, ec);

                    if (ec)
                        break;

                    mb += zp.total_in;
                    consumed += zp.total_out;

                    inner_buffer.commit(zp.total_out);
                    const auto fsz = ireader.put(inner_buffer.cdata(), ec);
                    inner_buffer.consume(fsz);
                }

            }
            return consumed ;
        }

        void
        finish(boost::system::error_code& ec)
        {

        }
    };

    struct writer
    {
        using inner_writer = typename InnerBody::writer;

        inner_writer iwriter;
        boost::beast::zlib::deflate_stream inf;
        boost::beast::zlib::z_params zp;
        bool deflate  = false ;
        boost::beast::flat_buffer inner_buffer;

        std::size_t yielded = 0u;

        using const_buffers_type = boost::asio::const_buffer;

        template<bool isRequest, class Fields>
        explicit
        writer(boost::beast::http::header<isRequest, Fields> const& h, value_type const& b) : iwriter(h, b)
        {
            auto itr = h.find(boost::beast::http::field::content_encoding);
            if (itr != h.end())
                deflate = boost::beast::iequals(itr->value(), "deflate");
        }

        void
        init(boost::system::error_code& ec)
        {
            ec = {};
        }

        boost::optional<std::pair<const_buffers_type, bool>>
        get(boost::system::error_code& ec)
        {
            auto ppo = iwriter.get(ec);
            if (!deflate || !ppo)
                return ppo;

            auto pp = *ppo;

            if (yielded > 0u)
                inner_buffer.consume(yielded);

            for (auto itr  = boost::asio::buffer_sequence_begin(pp.first);
                 itr != boost::asio::buffer_sequence_end(pp.first);
                 itr++)
            {
                boost::asio::const_buffer cb = *itr;
                while (!ec && cb.size() > 0u)
                {
                    zp.data_type = boost::beast::zlib::kind::unknown;
                    zp.next_in = cb.data();
                    zp.total_in = 0u;
                    zp.avail_in = cb.size();
                    boost::asio::mutable_buffer mb = inner_buffer.prepare(cb.size());
                    zp.next_out = mb.data();
                    zp.total_out = 0u;
                    zp.avail_out = mb.size();

                    inf.write(zp, pp.second ? boost::beast::zlib::Flush::finish : boost::beast::zlib::Flush::sync, ec);

                    if (ec)
                        break;
                    cb += zp.total_in;
                    inner_buffer.commit(zp.total_out);
                }

            }

            return std::pair<const_buffers_type, bool>{inner_buffer.cdata(), pp.second};

        }
    };

};

#endif //BEAST_ZLIB_BODY_HPP
