cmake_minimum_required(VERSION 3.10)

project(RDMS)

include_directories("RDMS/types" "RDMS/operations")

file( GLOB SOURCES "test/*.cpp" "RDMS/types/*.cpp" "RDMS/operations/*.cpp")

add_executable(aout ${SOURCES} )