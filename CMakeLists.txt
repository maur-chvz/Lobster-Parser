cmake_minimum_required(VERSION 3.20)
project(LobsterParser LANGUAGES CXX)

set(SOURCES
    src/lobster_parser.cpp
    src/lobster.cpp
)

set(HEADERS
    src/lobster_parser.h
)

add_executable(LobsterParser ${SOURCES} ${HEADERS})

target_include_directories(LobsterParser PRIVATE src)

target_compile_features(LobsterParser PRIVATE cxx_std_20)

set_target_properties(LobsterParser PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
