#ifndef LAB_10_LIST_H
#define LAB_10_LIST_H

#include <stdio.h>

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

// In / out
node_t *read_from_file(FILE *f);
void print_int_list(node_t *head);
void write_to_file(FILE *f, node_t *head);

// Create / free
node_t *create_node(void *data);
void free_list_all(node_t **head);

// Add / remove
void *pop_back(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);

// Reverse list using 3 pointers
node_t* reverse(node_t *head);

// Sort
int comparator_int(const void *, const void *);
node_t* sort(node_t *head, int (*comparator)(const void *, const void *)); //return new head
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

#endif //LAB_10_LIST_H
