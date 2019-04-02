#include <stdio.h>
#include <string.h>

char words[100][30];
char punctuation[10];
char user_input[302];

int word_count = 0;
int punctuation_count = 0;


int scan(char user_name[20]){
  printf("> %s: ", user_name);
  fgets(user_input, 302, stdin);

  if(strrchr(user_input, '\n') != NULL){return 0;} //within buffer
  else{return 1;} //exceeded buffer
}

void split(){
  int i;
  int str_i = 0;

  for(i = 0; i < 303; i++){
    if(user_input[i] == '\0'){
      //end of input
      word_count = 0;
      punctuation_count = 0;
      i = 303; //break
    }
    else if(user_input[i] == ' '){
      //end of word
      words[word_count][str_i] = '\0';
      word_count++;
      str_i = 0;
    }
    else if(strchr("!?.",user_input[i])){
      //punctuation
      punctuation[punctuation_count] = user_input[i];
      punctuation_count++;
    }
    else if(user_input[i] == '\n'){
      //skip
    }
    else{
      //new character
      words[word_count][str_i] = user_input[i];
      str_i++;
    }
  }
}

void parse_debug(){
  // debugging
  printf("\nDEBUGGING ENABLED -\n-------------------\n" );
  printf("input contents: %s", user_input);
  printf("words[0] contents: %s\n", words[0]);
  printf("punc[0] contents: %c\n", punctuation[0]);
  printf("-------------------\n");
  printf("word array contents with indexs:\n");
  int i, j;
  for(i = 0; i < 101; i++){
    printf("words[%d]='%s',\n", i, words[i]);
  }
  printf("-------------------\n");
  for(j = 0; j < 11; j++){
    printf("punctuation[%d]='%c',\n", j, punctuation[j]);
  }
  printf("--------END--------\n");
}
