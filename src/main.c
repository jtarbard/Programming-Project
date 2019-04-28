#include "interface.h"
#include "interpret.h"
#include "parse.h"
#include "score.h"
#include "response.h"
#include <stdio.h>
#include <string.h>

int main( int argc, char **argv ) {
  int inp_val, end;
  //interface.c
  interface();
  while(end == 0){
    //parse.c
    parse_malloc();
    inp_val = scan();
    while(inp_val != 0){
      respond("Conversation is a two person tango, it's no fun if you don't speak...");
      inp_val = scan();
    }
    end = split();
    if(end == 1){
      parse_free();
    }
    else{
      //interpret.c
      score_emotion();
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
