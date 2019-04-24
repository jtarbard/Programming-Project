//data structures
//parsed input linked lists
typedef struct word_struct {
    char *word;
    struct word_struct * next;
} word_type;

word_type * word_head;

typedef struct punc_struct {
    char punc;
    struct punc_struct * next;
} punc_type;

punc_type * punc_head;

char user_input[302];

//functions
int scan();
void split();
void run();
