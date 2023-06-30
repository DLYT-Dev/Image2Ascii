cmake_minimum_required(VERSION 3.20)
project(Image2Ascii VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23 LANGUAGES CXX)
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(lib/stb)
add_subdirectory(src)