#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//parsed input linked lists
struct word_struct {
    char *word;
    struct word_struct * next;
};
struct word_struct* word_head = NULL;
//
// typedef struct punc_struct {
//     char punc;
//     struct punc_struct * next;
// } punc_type;
// punc_type * punc_head = NULL;

//inital input char array
char user_input[302];


int scan(char user_name[20]){
  printf("> %s: ", user_name);
  fgets(user_input, 302, stdin);

  if(strrchr(user_input, '\n') != NULL){return 0;} //within buffer
  else{return 1;} //exceeded buffer
}

void split(){
  word_head = (struct word_struct*)malloc(sizeof(struct word_struct));

  struct word_struct* new_word = NULL;
  new_word = (struct word_struct*)malloc(sizeof(struct word_struct));

  int i;
  int string_index = 0;
  char *string;

  for(i = 0; i < 303; i++){
    //end of word
    if(user_input[i] == ' ' || user_input[i] == '\0'){
      printf("end of word: %s", string);
      struct word_struct * new_word = malloc(sizeof(new_word));
      new_word->word = strdup(string);
      new_word->next = word_head;
      word_head = new_word;

      printf(" - head: %s\n", word_head->word);
      printf(" - word: %s\n", new_word->word);
      //end of stream
      if(user_input[i] == '\0'){
        i = 303;
      }
      for(string_index; string_index != 0 ; string_index--){
        string[string_index] = 0;
        string[string_index-1] = '\0';
      }
    }
    //found punctuation
    // else if(strchr("!?.",user_input[i])){
    //   struct punc_struct* new_punc;
    //   new_punc = malloc(sizeof(punc_type));
    //   new_punc->punc = user_input[i];
    //   new_punc->next = punc_head;
    //   punc_head = new_punc;
    // }
    //carriage return
    else if(user_input[i] == '\n'){}
    //found new character
    else{
      string[string_index] = user_input[i];
      string_index++;
    }
  }
}

void run(){
  int i = 0;
  struct word_struct * current = word_head;

  while(current->next != NULL){
    printf("run: %s\n", current->word);
    i++;
    current = current->next;
  }
}
