cmake_minimum_required(VERSION 3.25)
project(spryx LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(spryx INTERFACE
        include/spryx/link.h)

target_include_directories(spryx INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(spryx INTERFACE
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
        include/spryx/rnea.h
        include/spryx/primitives.h
)

option(SPRYX_BUILD_TESTS "Build spryx tests" ON)
option(SPRYX_BUILD_EXAMPLES "Build spryx examples" ON)

if(SPRYX_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(SPRYX_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
