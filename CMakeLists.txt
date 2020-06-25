cmake_minimum_required(VERSION 3.16)
project(GBemu)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/EasyGL)

add_executable(GBemu main.cpp)

target_link_libraries(GBemu EasyGL)

include_directories(${CMAKE_SOURCE_DIR}/lib/EasyGL/include)