cmake_minimum_required(VERSION 3.10)

project(RDMS)

include_directories(RDMS/types)

file( GLOB SOURCES "test/*.cpp" "RDMS/types/*.cpp")

add_executable(aout ${SOURCES} )