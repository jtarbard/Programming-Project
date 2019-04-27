#include "interface.h"
#include "interpret.h"
#include "parse.h"
#include "score.h"
#include "response.h"
#include <stdio.h>
#include <string.h>

int main( int argc, char **argv ) {
  //interface.c
  interface();
  //parse.c
  scan();
  split();
  //interpret.c
  score_topics();
  get_response();
  //response.c
  respond(response);
  //interface.c
  end_print();
  //parse.c
  parse_free();
  return 0;
}
