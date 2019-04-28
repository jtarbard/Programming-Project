#include "parse.h"
#include "score.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
The interpret module will take the array of scores and attempt to calculate the most likely pre-programmed input match and then generate an array of the selected input matches.
*/
typedef struct response_struct {
  char* ada_favourite;
  char* ada_state;
  char* ada_question;
  char* user_statement;
  char* user_question;
} response_type;

char* response;
response_type personal[3] = {
  {
    "Pardon?",
    "I am named in honor of Ada Lovelace, a countess who is widely cited as the first programmer for her work on an algorithm for Charles Babbage's analyitcal engine.",
    "My name is Ada.",
    "Well it is nice to meet you!",
    "Pardon?"
  },
  {
    "Pardon?",
    "Hello!",
    "Hello!",
    "Hello!",
    "Hey, it's nice to meet you."
  },
  {
    "Pardon?",
    "I'm good thank you.",
    "I'm good thank you.",
    "How are you?",
    "How are you?"
  }
};

//ada state, ada question, user statement, user question
response_type films[3] = {
  {
    "My favourite film is A Street Car Name Desire.",
    "I have! I have to say I wasn't blown away though.",
    "I have! I thoroughly enjoyed it.",
    "I can't say I have, how did you find it?",
    "I can't say I have, how did you find it?"
  },
  {
    "My favourite film is A Street Car Name Desire.",
    "I have! I have to say I wasn't blown away though.",
    "I have! I thoroughly enjoyed it.",
    "I can't say I have, how did you find it?",
    "I can't say I have, how did you find it?"
  },
  {
    "My favourite film is A Street Car Name Desire.",
    "I have! I have to say I wasn't blown away though.",
    "I have! I thoroughly enjoyed it.",
    "I can't say I have, how did you find it?",
    "I can't say I have, how did you find it?"
  }
};

response_type tv[] = {
  "My favourite serise at the moment is The Good Place, it's on Netflix - go watch it.",
  "No, I'm not sure I have.",
  "No, I'm not sure I have.",
  "No, I'm not sure I have.",
  "No, I'm not sure I have."
};

response_type music[3] = {
  {
    "My favourite album is Channel Orange by Frank Ocean.",
    "I haven't no!",
    "I have.",
    "I haven't no!",
    "I have."
  }, //music
  {
    "My favourite song at the moment is Where U Are by Rina Sawayama.",
    "I haven't no!",
    "I have.",
    "I haven't no!",
    "I have."
  }, //song
  {
    "My favourite album is Channel Orange by Frank Ocean.",
    "I do!",
    "I do!",
    "I do!",
    "I do!"
  } //album
};

response_type books[] = {
    "My favourite book hmm... Probably The Great Gatsby by F. Scott Fitzgerald.",
    "I have, it was okay.",
    "I have, it was okay.",
    "I have, it was okay.",
    "I have, it was okay."
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
  // printf("getresp: user_topic: %s, fav?: %d\n", user_topics, favourite);
  if(user_topics != "unknown"){
    // printf("us_to: %s\n", user_topics);
    if(strstr(user_topics, "personal") != NULL){
      if(favourite == 0){
        response_calc(personal, user_topics_index);
      }
      else{
          response_calc(personal, user_topics_index);
      }
    }
    else if(strstr(user_topics, "films") != NULL){
      if(favourite == 0){
        response_calc(films, user_topics_index);
      }
      else{
          response = films[user_topics_index].ada_favourite;
      }
    }
    else if(strstr(user_topics, "tv") != NULL){
      if(favourite == 0){
        response_calc(tv, 0);
      }
      else{
        response = tv[0].ada_favourite;
      }
    }
    else if(strstr(user_topics, "music") != NULL){
      if(favourite == 0){
        response_calc(music, user_topics_index);
      }
      else{
        response = music[user_topics_index].ada_favourite;
      }
    }
    else if(strstr(user_topics, "books") != NULL){
      if(favourite == 0){
        response_calc(books, 0);
      }
      else{
        response = books[0].ada_favourite;
      }
    }
    else{response = "No response found...";}
  }
}
