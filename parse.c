#include <stdio.h>
#include <string.h>

char words[30][30];
char punctuation[10];
int word_count = 0;
int punctuation_count = 0;

char user_input[300];

void scan(){
  printf("> ");
  fgets(user_input, 300, stdin);
}

void split(){
  int i;
  int str_i = 0;

  for(i = 0; i < 301; i++){
    if(user_input[i] == '\0'){
      //end of input
      word_count = 0;
      punctuation_count = 0;
      i = 301; //break
    }
    else if(user_input[i] == ' '){
      //end of word
      words[word_count][str_i] = '\0';
      word_count++;
      str_i = 0;
    }
    else if(user_input[i] == '.' || user_input[i] == '?'){
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

int main( int argc, char **argv ) {

  scan();
  split();

// debugging
  #ifdef DEBUG
    printf("\nDEBUGGING ENABLED -\n-------------------\n" );
    printf("input contents: %s", user_input);
    printf("words[0] contents: %s\n", words[0]);
    printf("punc[0] contents: %c\n", punctuation[0]);
    printf("-------------------\n");
    printf("word array contents with indexs:\n");
    int i, j;
    for(i = 0; i < 31; i++){
      printf("words[%d]='%s',\n", i, words[i]);
    }
    printf("-------------------\n");
    for(j = 0; j < 11; j++){
      printf("punctuation[%d]='%c',\n", j, punctuation[j]);
    }
    printf("--------END--------\n");
  #endif
}
