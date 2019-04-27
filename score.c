#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *user_topics;
int user_topics_index = 0;
int blind = 1;

char *subject[2][6] = {
  {"ur","your","youre", "yours", "you", "ada"},
  {"me","mine","my","im","i", ""}
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
  }
  //question mark found
  else{
    return 1;
  }
  if(score > 0){
    return 1;
  }
  else{
    return 0;
  }
}

int score_subject(){
  int user = 0, ada = 0, word_index = 10, i, j;
  struct word_struct * current = word_head;

  while(current->next != NULL){
    for(i = 0; i < 2; i++){
      for(j = 0; j < 6; j++){
        if(subject[i][j] != "\0"){
          if(strstr(subject[i][j], current->word) != NULL){
            if(i == 0){ada += word_index;}
            else if(i == 1){user += word_index;}
            i = 2;
            j = 5;
          }
        }
      }
    }
    current = current->next;
    word_index--;
  }
  // printf("a:%d u:%d\n", ada, user);
  //score
  if(ada == user){
    return 2; //no subject found
  }
  else if(ada > user){
    return 1; //subject is ada
  }
  else{
    return 0; //subject is user
  }
}

void score_topics(){
  int i, j, found = 0;
  struct word_struct * current;
  current = word_head;

  while(found == 0 && current != NULL){
    for(i = 0; i < 6; i++){
      for(j = 0; j < 4; j++){
        // printf("topics[%d][%d]: %s - current: %s\n", i, j, topics[i][j], current->word);
          if((strstr(topics[i][j], current->word) != NULL) && (strlen(topics[i][j]) <= strlen(current->word))){
            // printf("found word!\n" );
            user_topics_index = j;
            if(i == 0){
              user_topics = "personal";
            }
            else if(i == 1){
              user_topics = "films";
            }
            else if(i == 2){
              user_topics = "tv";
            }
            else if(i == 3){
              user_topics = "music";
            }
            else if(i == 4){
              user_topics = "games";
            }
            else if(i == 5){
              user_topics = "books";
            }
            else{
              printf("err\n");
            }

            blind = 0;
            found = 1;
            i = 7;
            j = 5;
          }
      }
    }
    current = current->next;
  }
}
