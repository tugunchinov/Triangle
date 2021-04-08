cmake_minimum_required(VERSION 3.16)
project(Triangle)

set(CMAKE_CXX_STANDARD 20)

find_package(
        Boost 1.74 REQUIRED
        COMPONENTS  filesystem system
)
install(PROGRAMS ${Boost_LIBRARIES} DESTINATION ${CMAKE_SOURCE_DIR}/lib)

add_compile_options(-Wall -Wextra -pedantic -Werror)

set(SOURCES main.cpp src/window.cpp src/api.cpp)

add_executable(Triangle ${SOURCES})
target_include_directories(Triangle PUBLIC include)
target_link_libraries(Triangle X11)