#include "interface.h"
#include "response.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//parsed input linked lists
typedef struct word_struct {
    char *word;
    struct word_struct * next;
} word_type;
word_type * word_head;
//inital input char array
char user_input[302];
char user_name[20];
int punctuation = 0;

int parse_malloc(){
  word_type * word_head = NULL;
  return 0;
}

int parse_free(){
  word_type * list_ptr;

  while(word_head != NULL) {
    list_ptr = word_head;
    if(list_ptr->word != NULL){
      free(list_ptr->word); //SEGFAULT
    }
    word_head = list_ptr->next;
    free(list_ptr);
  }
  free(word_head);
}

int scan(){
  printf("> %s: ", user_name);
  fgets(user_input, 302, stdin);
  if(user_input[0] == '\n'){
    return 1;
  }
  else{
    return 0;
  }
}

int split(){
  int exit_check = 0, i = 0;
  char *string;
  string = malloc(sizeof(sizeof(char) * 30));
  strcpy(string, "");
  //strcat workaround
  char strcat_fix[2];
  strcat_fix[1] = '\0';

  while(user_input[i] != '\0'){
    //end of word
    if(user_input[i] == ' ' || user_input[i] == '\n'){
      if(exit_check == 0){
        if(strstr("goodbye", string) != NULL){
          respond("Farwell!");
          free(string);
          parse_free();
          return 1;
        }
        else{
          exit_check = 1;
        }
      }
      //define and allocate to heap
      word_type * new_word = NULL;
      new_word = (struct word_struct*)malloc(sizeof(struct word_struct));

      new_word->word = strdup(string);
      new_word->next = word_head;
      word_head = new_word;
      // printf("parse.c: %s\n", word_head->word);
      strcpy(string, "");
      // end of stream
      if(user_input[i] == '\0'){ //SEGFAULT
        i = 302;
      }
    }
    // found punctuation
    else if(strchr("!?.-;\"$%£'{}()[]*+/\\:<>=@^_`¬~#", user_input[i]) != NULL){
      if(strchr("?", user_input[i]) != NULL){punctuation = 1;}
    }
    //found new character
    else{
      // printf("%c", user_input[i]);
      strcat_fix[0] = user_input[i];
      strcat(string, strcat_fix);
    }
    i++;
  }
  free(string);
  return 0;
}
