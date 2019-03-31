#include "parse.h"
#include <stdio.h>
#include <string.h>

int welcome(){
  printf(" █████╗ ██████╗  █████╗ \n");
  printf("██╔══██╗██╔══██╗██╔══██╗\n");
  printf("███████║██║  ██║███████║\n");
  printf("██╔══██║██║  ██║██╔══██║\n");
  printf("██║  ██║██████╔╝██║  ██║\n");
  printf("╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝\n");
}

int setup(){
  //user setup
  char user_name[20];
  fgets(user_name, 20, stdin);
}

int main( int argc, char **argv ) {
  //parse functions
  scan();
  split();
}
