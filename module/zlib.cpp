//
// Copyright (c) 2024 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

module;
#include <boost/beast/zlib.hpp>

export module boost.beast.zlib ;

namespace boost::beast::zlib
{

export using boost::beast::zlib::deflate_stream;
export using boost::beast::zlib::inflate_stream;
export using boost::beast::zlib::z_params;
export using boost::beast::zlib::deflate_upper_bound;
export using boost::beast::zlib::error;
export using boost::beast::zlib::Flush;
export using boost::beast::zlib::Strategy;


}