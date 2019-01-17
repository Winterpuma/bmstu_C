#ifndef LIST_H
#define LIST_H

typedef struct node
{
    struct node *next;
    struct node *prev;
    void *data;
} node;

void push(node **list, void *data, int index);
node *pop(node *list_h, int index);
void print(node *list, int flag_student);
void free_list(node *list, int flag_student);

#endif
