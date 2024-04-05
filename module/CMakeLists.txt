add_library(boost_beast_module)

target_sources(boost_beast_module
        PUBLIC
        FILE_SET CXX_MODULES FILES
        buffers.cpp core.cpp http.cpp websocket.cpp zlib.cpp
)

add_library(boost::module::beast ALIAS boost_beast_module)

target_link_libraries(boost_beast_module PUBLIC Boost::beast)