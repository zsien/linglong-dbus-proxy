cmake_minimum_required(VERSION 3.14)
project(ll-dbus-proxy)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)

pkg_check_modules(libsystemd REQUIRED IMPORTED_TARGET libsystemd)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_subdirectory(src)
