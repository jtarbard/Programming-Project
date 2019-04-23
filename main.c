#include "parse.h"
#include "score.h"
#include "interface.h"
#include <stdio.h>
#include <string.h>

int main( int argc, char **argv ) {
  //intro
  welcome();
  setup();
  //parse functions
  int buffer;
  buffer = scan(user_name);
  split();

  if(buffer == 1){
    printf("> Ada: TEMP RESPONSE - buffer exceeded. Limit 300 characters.\n");
  }

  getTopics();

  //end of chat line
  printf("--Chat:Ended------------\n");
  // debug();

}
