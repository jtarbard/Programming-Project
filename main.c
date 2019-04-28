#include "interface.h"
#include "interpret.h"
#include "parse.h"
#include "score.h"
#include "response.h"
#include <stdio.h>
#include <string.h>

int main( int argc, char **argv ) {
  int end;
  //interface.c
  interface();
  while(end == 0){
    //parse.c
    parse_malloc();
    scan();
    end = split();
    if(end == 1){
      parse_free();
    }
    else{
      //interpret.c
      score_topics();
      get_response();
      //response.c
      respond(response);
      //parse.c
      parse_free();
    }
  }

  //interface.c
  end_print();
  return 0;
}
