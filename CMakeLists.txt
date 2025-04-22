cmake_minimum_required(VERSION 3.10.0)
project(zipapp VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra")

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(libzip REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE libzip::zip)
find_package(ZLIB REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ZLIB::ZLIB)

