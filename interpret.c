#include "score.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
The interpret module will take the array of scores and attempt to calculate the most likely pre-programmed input match and then generate an array of the selected input matches.
*/
typedef struct response_struct {
  char* ada_state;
  char* ada_question;
  char* user_statement;
  char* user_question;
} response_type;

char* response;

response_type personal[4] = {
  {"I am named after Ada Lovelace.","My name is Ada.","Well it is nice to meet you!","Yes."}, //name
  {"ada state ran","ada q ran","user state ran","usrer q ran"}, //old
  {"ada state ran","ada q ran","user state ran","usrer q ran"}, //children
  {"ada state ran","ada q ran","user state ran","usrer q ran"}, //color
};

int response_calc(response_type arr[], int index){
  int ada, question;
  ada = score_subject();
  question = score_question();

  // printf("scores: ada %d, question: %d\n", ada, question);
  if(ada == 0){
    if(question == 0){
      response = arr[index].user_statement;
    }
    else{
      response = arr[index].user_question;
    }
  }
  else{
    if(question == 0){
      response = arr[index].ada_state;
    }
    else{
      response = arr[index].ada_question;
    }
  }
}

int get_response(){
  if(blind == 0){
    // printf("us_to: %s\n", user_topics);
    if(strstr(user_topics, "personal") != NULL){
      response_calc(personal, user_topics_index);
    }
    else if(strstr(user_topics, "films") != NULL){
      response_calc(personal, user_topics_index);
    }
    else if(strstr(user_topics, "tv") != NULL){
      response_calc(personal, user_topics_index);
    }
    else if(strstr(user_topics, "games") != NULL){
      response_calc(personal, user_topics_index);
    }
    else if(strstr(user_topics, "books") != NULL){
      response_calc(personal, user_topics_index);
    }
    else{response = "No response found...";}
  }
  else{
    printf("GET_RESPONSE HAS NO TOPIC\n");
  }
}
