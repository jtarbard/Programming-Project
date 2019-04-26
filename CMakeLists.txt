cmake_minimum_required (VERSION 2.6)
project (ada)

include_directories(include)

add_executable(ada main.c interface.c parse.c score.c interpret.c)

