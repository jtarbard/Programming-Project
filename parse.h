//data structures
//parsed input linked lists
typedef struct word_struct {
    char *word;
    struct word_struct * next;
} word_type;

word_type * word_head;

char user_input[302];
int punctuation;

//functions
int scan();
int split();
int run();
int parse_malloc();
int parse_free();
