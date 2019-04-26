typedef struct response_struct {
  char* ada_state;
  char* ada_question;
  char* user_statement;
  char* user_question;
} response_type;

int response_calc(response_type arr[], int index);
int get_response();
