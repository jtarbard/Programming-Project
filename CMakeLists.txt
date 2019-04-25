cmake_minimum_required (VERSION 2.6)
project (ada)

include_directories(include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(ada main.c interface.c parse.c score.c)
