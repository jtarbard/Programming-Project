#include "score.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>

/**
The interpret module will take the array of scores and attempt to calculate the most likely pre-programmed input match and then generate an array of the selected input matches.
*/
//if topic found
//parse xml file for topic
//pick response
//call return of response
xmlDoc *xml;
xmlNode *root, *topic_branch, *topic;

int xml_init(){
  char *dir;

  if(blind == 0){
    dir = "topics.xml";
  }
  else{
    dir = "blind.xml";
  }

  xml = xmlReadFile(dir, NULL, 0);
  root = xmlDocGetRootElement(xml);
  //notice end.
  topic_branch = root->children; //branch of topics

  return 0;
}

int branch_selector(){
  xmlNode *temp;
  temp = topic_branch;
  char *str;
  str = malloc(sizeof(str));

  while(temp != NULL){
    str = xmlNodeGetContent(temp);
    printf("%s\n", str);
    printf("%s\n", user_topics[0]);
    if(str == user_topics[0]){
      topic = temp;
      printf("found\n" );
      temp = NULL;
    }
    else{
    temp = temp->next;
    }
  }
  free(str);
  return 0;
}

int interpret_free(){
  xmlFree(xml);
}
