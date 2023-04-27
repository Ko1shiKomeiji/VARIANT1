#define N 40

struct Data {
    double f;
    char s[2];
};

typedef struct Node {
    struct Data data;
    struct Node *next;
    struct Node *prev;
} node;

int llength(node *head);
void lprint(node *head);
node *add_head(node *head, struct Data *data);
node *reverse(node *head);
void reverse1(node *head_ref);
