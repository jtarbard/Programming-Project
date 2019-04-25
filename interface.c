#include "parse.h"
#include <stdio.h>
#include <string.h>

/**
* interface.c:
* Contains functions relating to the user
* facing terminal interface. Primarily
* cosmetic.
*/

char user_name[20];

int print_welcome(){
  printf("-------Welcome To-------\n");
  printf(" █████╗ ██████╗  █████╗ \n");
  printf("██╔══██╗██╔══██╗██╔══██╗\n");
  printf("███████║██║  ██║███████║\n");
  printf("██╔══██║██║  ██║██╔══██║\n");
  printf("██║  ██║██████╔╝██║  ██║\n");
  printf("╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝\n");
  printf("---------Chatbot--------\n");

  return 0;
}

int get_username(){
  printf("Enter screen name: ");
  fgets(user_name, 20, stdin);
  printf("%c\n", user_name[strlen(user_name)]);

  //prevents username carriage return
  char *newline;
  if ((newline=strchr(user_name, '\n')) != NULL){
    *newline = '\0';
  }

  printf("--Chat:Begun------------\n");
}

int interface(){
  print_welcome();
  get_username();

  return 0;
}
