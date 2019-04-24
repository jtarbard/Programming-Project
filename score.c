#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *user_topics[5];
int user_topics_index = 0;

char *subject[2][5] = {
  {"ada","you","your","you're", ""},
  {"i","im","my","mine","me"}
};

char *question[9] = {"what","when","where","which","who","whoose","why","how","?"};

char *topics[6][4] = {
  {"name", "age", "children", "colour"}, //0 - personal information
  {"film", "movie", "", ""}, //1 - films
  {"tv", "television", "", ""}, //2 - tv
  {"music", "song", "album", ""}, //3 - music
  {"game", "", "", ""}, //4 - games
  {"book", "novel", "", ""} //5 - books
};

void getSubject(){
  int user, ada, i, j;
  word_type * current = word_head;

  while(current != NULL){
    for(i = 0; i < 5; i++){
      if(subject[i][j][0] != '\0'){
        if(strstr(current->word, subject[0][i]) != NULL){user++;}
      }
      current = current->next;
    }

    for(j = 0; j < 5; j++){
      if(subject[i][j][0] != '\0'){
        if(strstr(current->word, subject[0][j]) != NULL){ada++;}
      }
      current = current->next;
    }
  }
}

void getTopics(){
  int i, j;
  word_type * current = word_head;

  while(current->next != NULL){
    printf("while: %s\n", current->word);
    for(i = 0; i < 6; i++){
      for(j = 0; j < 5; j++){
        if(topics[i][j][0] != '\0'){
          if(strstr(current->word, topics[i][j]) != NULL){
            user_topics[user_topics_index] = current->word;
            i = 6;
            j = 5;
          }
        }
      }
    }
    current = current->next;
  }
}
