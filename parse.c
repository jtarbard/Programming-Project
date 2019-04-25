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

int scan(char user_name[20]){
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
  int i;
  int string_index = 0;
  char *string;

  //allocate to heap
  word_head = malloc(sizeof(word_type));

  for(i = 0; i < 303; i++){
    //end of word
    if(user_input[i] == ' ' || user_input[i] == '\0'){
      //define and allocate to heap
      word_type * new_word = NULL;
      new_word = (struct word_struct*)malloc(sizeof(struct word_struct));

      new_word->word = strdup(string);
      new_word->next = word_head;
      word_head = new_word;
      //end of stream
      if(user_input[i] == '\0'){
        i = 303;
      }
      for(string_index; string_index != 0 ; string_index--){
        string[string_index] = 0;
        string[string_index-1] = '\0';
      }
    }
    // found punctuation
    else if(strchr("!?.-;\"$%£'{}()[]*+/\\:<>=@^_`¬~#", user_input[i]) != NULL){
      if(strchr("?", user_input[i]) != NULL){punctuation = 1;}
    }
    //carriage return
    else if(user_input[i] == '\n'){}
    //found new character
    else{
      string[string_index] = user_input[i];
      string_index++;
    }
  }
}

int parse_free(){
  word_type * temp;

  while(temp != NULL){
    temp = word_head;
    free(word_head->word);
    word_head = word_head->next;
    free(temp);
  }

  return 0;
}
