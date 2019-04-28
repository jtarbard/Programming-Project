#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *user_topics;
int user_topics_index = 0;
int emotion; //-1: negative, 0: netural, 1: positive
int favourite;

char *subject[2][6] = {
  {"ur","your","youre", "yours", "you", "ada"},
  {"me","mine","my","im","i", ""}
};

char *question[9] = {"what","when","where","which","who","whoose","why","how","?"};

char *perspective[2][8] = {
  {"bad", "awful", "terrible", "hate","hated", "dislike","disliked", "not"},
  {"good","great","brilliant","love","loved","like","liked","fan"}
};

char *topics[6][4] = {
  {"name", "hi", "are", ""}, //0 - personal information
  {"film", "movie", "seen", ""}, //1 - films
  {"tv", "television", "", ""}, //2 - tv
  {"music", "song", "album", ""}, //3 - music
  {"book", "novel", "read", ""} //5 - books
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

  while(current != NULL){
    for(i = 0; i < 2; i++){
      for(j = 0; j < 6; j++){
        if(subject[i][j] != "\0"){
          if(current->word != NULL && subject[i][j] == current->word){
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
    return 1; //no subject found
  }
  else if(ada > user){
    return 1; //subject is ada
  }
  else{
    return 0; //subject is user
  }
}

int score_emotion(){
  int emotion = 0, pos = 0, neg=0, i, j;
  favourite = 0;
  struct word_struct * current;
  current = word_head;

  while(current != NULL && current->word != NULL){
    // printf("score emotion: current: %s\n", current->word);
    if(strstr(current->word, "favourite") != NULL){
      // printf("found favv\n" );
      favourite = 1;
    }
    for(i = 0; i < 2; i++){
      for(j = 0; j < 8; j++){
        if((strstr(perspective[i][j], current->word)) == perspective[i][j]){
          if(i == 0){
            neg++;
          }
          else{
            pos++;
          }
        }
      }
    }
    current = current->next;
  }
  if(neg == pos){
    emotion = 0;
  }
  else if( pos > neg){
    emotion = 1;
  }
  else{
    emotion = -1;
  }
  return emotion;
}

int score_topics(){
  int i, j, found = 0;
  user_topics = NULL;
  struct word_struct * current;
  current = word_head;

  while(found == 0 && current != NULL && current->word != NULL){
    // printf("score topics: current: %s\n", current->word);
    for(i = 0; i < 5; i++){
      for(j = 0; j < 4; j++){
        if((strstr(topics[i][j], current->word)) == topics[i][j]){
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
            user_topics = "books";
          }
          else{
            printf("err\n");
          }
          // printf("found topic: %s\n", user_topics);

          found = 1;
          i = 7;
          j = 5;
        }
      }
    }
    current = current->next;
  }

  if(user_topics == NULL){
    user_topics = "unknown";
  }
  return 0;
}
