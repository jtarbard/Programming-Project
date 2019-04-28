cmake_minimum_required (VERSION 2.6)
project (ada)

include_directories(include)

add_executable(ada 
src/main.c 
src/interface.c 
src/parse.c 
src/score.c 
src/interpret.c 
src/response.c
)

