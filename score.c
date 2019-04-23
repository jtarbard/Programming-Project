#include "parse.h"
#include <string.h>
#include <stdio.h>

char user_topics[5][20];
int user_topics_index = 0;

char subject[2][6][20] = {
  {"ada","you","your","you're"},
  {"i","im","my","mine","me",'\0'}
}; //who is the sentence about

char question[9][20] = {"what","when","where","which","who","whoose","why","how",'?'}; //is it a question

char topics[6][4][20] = {
  {"name", "age", "children", "colour"}, //0 - personal information
  {"film", "movie", "", ""}, //1 - films
  {"tv", "television", "", ""}, //2 - tv
  {"music", "song", "album", ""}, //3 - music
  {"game", "", "", ""}, //4 - games
  {"book", "novel", "", ""} //5 - books
};

void getTopics(){
  int i, j;
  int k = 0;
  do{
    for(i = 0; i <= 5; i++){
      for(j = 0; j <= 4; j++){
        if(topics[i][j][0] == '\0'){
          //pass
        }
        else{
          if(strstr(words[k], topics[i][j]) != NULL){
            memcpy(user_topics[user_topics_index], topics[i][j], strlen(user_topics[user_topics_index])+1);
            user_topics_index++;
            i = 5; //break
            j = 5; //break
          }
        }
      }
    }
    k++;
  } while(k < 99);
}
