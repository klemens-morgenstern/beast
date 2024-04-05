//
// Copyright (c) 2024 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

module;
#include <boost/beast/core.hpp>
#include <boost/beast.hpp>

export module boost.beast.core ;

namespace boost::beast
{

// Classes

export using boost::beast::async_base;
export using boost::beast::basic_stream;
export using boost::beast::file;
export using boost::beast::file_mode;
#if BOOST_BEAST_USE_POSIX_FILE
export using boost::beast::file_posix;
#endif

export using boost::beast::file_stdio;
#if ! defined(BOOST_BEAST_USE_WIN32_FILE)
export using boost::beast::file_win32;
#endif
export using boost::beast::flat_stream;
export using boost::beast::iequal;
export using boost::beast::iless;
export using boost::beast::rate_policy_access;
export using boost::beast::saved_handler;
export using boost::beast::simple_rate_policy;
export using boost::beast::static_string;
export using boost::beast::stable_async_base;
export using boost::beast::string_view;
export using boost::beast::tcp_stream;
export using boost::beast::unlimited_rate_policy;

// Constants

export using boost::beast::condition;
export using boost::beast::error;
export using boost::beast::file_mode;
export using boost::beast::role_type;
// Functions
export using boost::beast::allocate_stable;
export using boost::beast::async_detect_ssl;
export using boost::beast::beast_close_socket;
export using boost::beast::bind_front_handler;
export using boost::beast::bind_handler;
export constexpr inline detail::close_socket_impl close_socket{};
export using boost::beast::detect_ssl;
export using boost::beast::generic_category;
export using boost::beast::get_lowest_layer;
export using boost::beast::iequals;
export using boost::beast::to_static_string;
// Type Traits
export using boost::beast::executor_type;
export using boost::beast::has_get_executor;
export using boost::beast::is_async_read_stream;
export using boost::beast::is_async_stream;
export using boost::beast::is_async_write_stream;
export using boost::beast::is_file;
export using boost::beast::is_sync_read_stream;
export using boost::beast::is_sync_stream;
export using boost::beast::is_sync_write_stream;
export using boost::beast::lowest_layer_type;
// Aliases
export namespace errc =  boost::system::errc;
export using boost::beast::error_category;
export using boost::beast::error_code;
export using boost::beast::error_condition;
export using boost::beast::system_category;
export using boost::beast::system_error;

}