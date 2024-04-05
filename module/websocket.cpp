//
// Copyright (c) 2024 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at websocket://www.boost.org/LICENSE_1_0.txt)
//

module;
#include <boost/beast/websocket.hpp>

export module boost.asio.websocket ;

namespace boost::beast::websocket
{


// Classes
export using boost::beast::websocket::close_reason;
export using boost::beast::websocket::ping_data;
export using boost::beast::websocket::stream;
export using boost::beast::websocket::stream_base;
export using boost::beast::websocket::reason_string;
// Functions
export using boost::beast::websocket::async_teardown;
export using boost::beast::websocket::is_upgrade;
export using boost::beast::websocket::seed_prng;
export using boost::beast::websocket::teardown;
// Options
export using boost::beast::websocket::permessage_deflate;
// Constants
export using boost::beast::websocket::close_code;
export using boost::beast::websocket::condition;
export using boost::beast::websocket::error;
export using boost::beast::websocket::frame_type;

}