#include "parse.h"
#include <stdio.h>
#include <string.h>

char user_name[20];

int welcome(){
  printf("-------Welcome To-------\n");
  printf(" █████╗ ██████╗  █████╗ \n");
  printf("██╔══██╗██╔══██╗██╔══██╗\n");
  printf("███████║██║  ██║███████║\n");
  printf("██╔══██║██║  ██║██╔══██║\n");
  printf("██║  ██║██████╔╝██║  ██║\n");
  printf("╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝\n");
  printf("---------Chatbot--------\n");
}

int setup(){
  //user setup
  printf("Enter screen name: ");
  fgets(user_name, 20, stdin);
  int i;
  printf("%c\n", user_name[strlen(user_name)]);

  char *newline;
  if ((newline=strchr(user_name, '\n')) != NULL){
    *newline = '\0';
  }
  //begining of chat line
  printf("--Chat:Begun------------\n");
}

int main( int argc, char **argv ) {
  //intro
  welcome();
  setup();
  //parse functions
  scan(user_name);
  split();
  //end of chat line
  printf("--Chat:Ended------------\n");
}
