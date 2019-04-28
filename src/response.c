#include "parse.h"
#include <stdio.h>

int respond(char* response){
  printf("> ada: %s\n", response);
  return 0;
}

int double_response(char* first, char* second){
  respond(first);
  scan();
  respond(second);

  return 0;
}
