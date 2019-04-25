#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *user_topics[10];
int user_topics_index = 0;

char *subject[2][5] = {
  {"ur","your","you're", "you", "ada"},
  {"me","mine","my","im","i"}
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

int score_question(){
  int score = 0, i;
  struct word_struct * current = word_head;

  //question mark not found
  if(punctuation == 0){
    while(current->next != NULL){
      for(i = 0; i < 9; i++){
          if(question[i] != "\0"){
            if(strstr(current->word, question[i]) != NULL){
              score++;
              i = 9;
            }
          }
        }
      current = current->next;
    }
    return score;
  }
  //question mark found
  else{
    return 10;
  }
}

int score_subject(){
  int user = 0, ada = 0, i, j;
  struct word_struct * current = word_head;

  while(current->next != NULL){
    for(i = 0; i < 2; i++){
      for(j = 0; j < 5; j++){
        if(subject[i][j] != "\0"){
          if(strstr(subject[i][j], current->word) != NULL){
            if(i == 0){ada += j;}
            else if(i == 1){user += j;}
            i = 2;
            j = 5;
          }
        }
      }
    }
    current = current->next;
  }
  //score
  if(ada == user){
    return 0; //no subject found
  }
  else if(ada > user){
    return 1; //subject is ada
  }
  else{
    return 2; //subject is user
  }
}

void score_topics(){
  int i, j;
  struct word_struct * current = word_head;

  while(current->next != NULL){
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
