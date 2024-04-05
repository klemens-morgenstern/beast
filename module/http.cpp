//
// Copyright (c) 2024 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

module;
#include <boost/beast/http.hpp>

export module boost.asio.http ;

namespace boost::beast::http
{


export using boost::beast::http::basic_chunk_extensions;
export using boost::beast::http::basic_dynamic_body;
export using boost::beast::http::basic_fields;
export using boost::beast::http::basic_file_body;
export using boost::beast::http::basic_parser;
export using boost::beast::http::basic_string_body;
export using boost::beast::http::buffer_body;
export using boost::beast::http::chunk_body;
export using boost::beast::http::chunk_crlf;
export using boost::beast::http::chunk_extensions;
export using boost::beast::http::chunk_header;
export using boost::beast::http::chunk_last;
export using boost::beast::http::dynamic_body;
export using boost::beast::http::empty_body;
export using boost::beast::http::fields;
export using boost::beast::http::file_body;
export using boost::beast::http::header;
export using boost::beast::http::message;
export using boost::beast::http::message_generator;
export using boost::beast::http::parser;
export using boost::beast::http::request;
export using boost::beast::http::request_header;
export using boost::beast::http::request_parser;
export using boost::beast::http::request_serializer;
export using boost::beast::http::response;
export using boost::beast::http::response_header;
export using boost::beast::http::response_parser;
export using boost::beast::http::response_serializer;
export using boost::beast::http::serializer;
export using boost::beast::http::span_body;
export using boost::beast::http::string_body;
export using boost::beast::http::vector_body;

// Functions

export using boost::beast::http::async_read;
export using boost::beast::http::async_read_header;
export using boost::beast::http::async_read_some;
export using boost::beast::http::async_write;
export using boost::beast::http::async_write_header;
export using boost::beast::http::async_write_some;
export using boost::beast::http::int_to_status;
export using boost::beast::http::make_chunk;
export using boost::beast::http::make_chunk_last;
export using boost::beast::http::obsolete_reason;
export using boost::beast::http::operator<<;
export using boost::beast::http::read;
export using boost::beast::http::read_header;
export using boost::beast::http::read_some;
export using boost::beast::http::string_to_field;
export using boost::beast::http::string_to_verb;
export using boost::beast::http::swap;
export using boost::beast::http::to_string;
export using boost::beast::http::to_status_class;
export using boost::beast::http::write;
export using boost::beast::http::write_header;
export using boost::beast::http::write_some;

// Constants

export using boost::beast::http::error;
export using boost::beast::http::field;
export using boost::beast::http::status;
export using boost::beast::http::status_class;
export using boost::beast::http::verb;

// Type Traits
export using boost::beast::http::is_body;
export using boost::beast::http::is_body_reader;
export using boost::beast::http::is_body_writer;
export using boost::beast::http::is_fields;
export using boost::beast::http::is_mutable_body_writer;

// Concepts
export using boost::beast::http::ext_list;
export using boost::beast::http::opt_token_list;
export using boost::beast::http::param_list;
export using boost::beast::http::token_list;


}