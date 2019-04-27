#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//parsed input linked lists
typedef struct word_struct {
    char *word;
    struct word_struct * next;
} word_type;
word_type * word_head = NULL;
//inital input char array
char user_input[302];
int punctuation = 0;
char user_name[20];

int scan(){
  printf("> %s: ", user_name);
  fgets(user_input, 302, stdin);

  if(strrchr(user_input, '\n') != NULL){
    return 0;
  } //within buffer
  else{
    return 1;
  } //exceeded buffer
}

void split(){
  int i = 0;
  char *string;
  string = malloc(sizeof(sizeof(char) * 30));
  //strcat workaround
  char strcat_fix[2];
  strcat_fix[1] = '\0';

  word_head = malloc(sizeof(word_type));

  while(user_input[i] != '\0'){
    //end of word
    if(user_input[i] == ' ' || user_input[i] == '\n'){
      //define and allocate to heap
      word_type * new_word = NULL;
      new_word = (struct word_struct*)malloc(sizeof(struct word_struct));

      new_word->word = strdup(string);
      new_word->next = word_head;
      word_head = new_word;

      strcpy(string, "");
      //end of stream
      if(user_input[i] == '\0'){
        i = 302;
      }
    }
    // found punctuation
    else if(strchr("!?.-;\"$%£'{}()[]*+/\\:<>=@^_`¬~#", user_input[i]) != NULL){
      if(strchr("?", user_input[i]) != NULL){punctuation = 1;}
    }
    //found new character
    else{
      strcat_fix[0] = user_input[i];
      strcat(string, strcat_fix);
    }
    i++;
  }
  free(string);
}

void parse_free(){
  word_type * list_ptr;

  while (word_head) {
  list_ptr = word_head;
  if(list_ptr->word != NULL){
    free(list_ptr->word);
  }
  word_head = list_ptr->next;
  free(list_ptr);
  }
}
