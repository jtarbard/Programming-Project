#include "interface.h"
#include "parse.h"
#include "score.h"
#include <stdio.h>
#include <string.h>

int main( int argc, char **argv ) {
  //intro
  interface();

  scan(user_name);
  split();

  // printf("question score: %d\n", score_question());
  // printf("subject score: %d\n", score_subject());

  score_question();
  score_subject();
  score_topics();
  //end of chat line
  printf("--Chat:Ended------------\n");
  parse_free();

  return 0;
}
