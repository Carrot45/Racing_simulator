project(Transport_library VERSION 1.0.0)

file(GLOB_RECURSE TRANS_SRC "src/*.cpp")
file(GLOB_RECURSE TRANS_HEADERS "include/*.h")

add_library(Transport_library SHARED ${TRANS_SRC} ${TRANS_HEADERS})

target_include_directories(Transport_library
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(Transport_library 
    PRIVATE TRANSPORT_LIBRARY_EXPORTS
)

set_target_properties(Transport_library PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS FALSE
)