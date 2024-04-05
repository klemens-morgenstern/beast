//
// Copyright (c) 2024 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

module;
#include <boost/beast/core.hpp>
#include <boost/beast/core/buffer_ref.hpp>

export module boost.beast.buffers ;

namespace boost::beast
{

export using boost::beast::basic_flat_buffer;
export using boost::beast::basic_multi_buffer;
export using boost::beast::buffer_ref;
export using boost::beast::buffered_read_stream;
export using boost::beast::buffers_adaptor;
export using boost::beast::buffers_cat_view;
export using boost::beast::buffers_prefix_view;
export using boost::beast::buffers_suffix;
export using boost::beast::flat_buffer;
export using boost::beast::flat_static_buffer;
export using boost::beast::flat_static_buffer_base;
export using boost::beast::multi_buffer;
export using boost::beast::static_buffer;
export using boost::beast::static_buffer_base;
// Functions
export using boost::beast::async_write;

constexpr inline detail::buffer_bytes_impl buffer_bytes{};

export using boost::beast::buffers_cat;
export using boost::beast::buffers_front;
export using boost::beast::buffers_prefix;
export using boost::beast::buffers_range;
export using boost::beast::buffers_range_ref;
export using boost::beast::buffers_to_string;
export using boost::beast::make_printable;
export using boost::beast::ostream;
export using boost::beast::read_size;
export using boost::beast::read_size_or_throw;
export using boost::beast::ref;
export using boost::beast::write;
// Type Traits
export using boost::beast::buffers_iterator_type;
export using boost::beast::buffers_type;
export using boost::beast::is_buffers_generator;
export using boost::beast::is_const_buffer_sequence;
export using boost::beast::is_mutable_buffer_sequence;


}