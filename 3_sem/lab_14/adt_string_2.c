#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_string_all.h"

typedef struct node* node_t;

struct node
{
    char ch;
    struct node *next;
};

struct string_type
{
    struct node *top;

};

string_t str_allocate(void);
node_t create_node(char ch);
void str_add_char(string_t *s, char ch);
void str_add_str(string_t *s, char text[]);


/**
 * Allocate memory for new string
 * @return new string
 */
string_t str_allocate(void)
{
    string_t s = calloc(1, sizeof(struct string_type));
    return s;
}

/**
 * Create new string
 * @param str - string for filling
 * @return new string
 */
string_t str_create(char *str)
{
    string_t s = NULL;
    str_add_str(&s, str);

    return s;
}

/**
 * Create new node
 * @param ch - char
 * @return created node
 */
node_t create_node(char ch)
{
    node_t node = calloc(1, sizeof(struct node));

    if (node)
        node->ch = ch;

    return node;
}

/**
 * Add char to string
 * @param s - string
 * @param ch - char
 */
void str_add_char(string_t *s, char ch)
{
    node_t new_node = create_node(ch);
    node_t curr;

    if (!s || !(*s))
        *s = str_allocate();

    if (!(*s)->top)
        (*s)->top = new_node;
    else
    {
        curr = (*s)->top;
        for ( ; curr->next; curr = curr->next);
        curr->next = new_node;
    }
}

/**
 * Add string to string
 * @param s - string
 * @param text - text to add
 */
void str_add_str(string_t *s, char *text)
{
    size_t len = strlen(text);
    for (int i = 0; i < len; i++)
        str_add_char(s, text[i]);
}

/**
 * Print out string to console
 * @param s - string
 */
void str_print(string_t s)
{
    node_t curr;
    if (s)
    {
        if (!s->top)
            puts("String is empty.");
        else
        {
            curr = s->top;
            for ( ; curr; curr = curr->next)
                switch (curr->ch)
                {
                    case '\0':
                        printf("\\0");
                        break;
                    case '\n':
                        printf("\\n");
                        break;
                    case '\t':
                        printf("\\t");
                        break;
                    default:
                        printf("%c", curr->ch);
                        break;
                }
        }
    }
    else
        puts("Err. String doesn't exist.");
}

/**
 * Concatenate two existing strings
 * @param s1 - string to change
 * @param s2 - string to add
 */
string_t str_concatenate(string_t s1, string_t s2)
{
    string_t new = str_create("");
    node_t curr;
    if (s1 && s1->top)
    {
        curr = s1->top;
        for ( ; curr; curr = curr->next)
            str_add_char(&new, curr->ch);
    }

    if (s2 && s2->top)
    {
        curr = s2->top;
        for ( ; curr; curr = curr->next)
            str_add_char(&new, curr->ch);
    }
    return new;
}

/**
 * Compare two strings
 * @param s1 - string 1
 * @param s2 - string 2
 * @return 1 if equal, 0 - else
 */
int str_compare(string_t s1, string_t s2)
{
    int res = 1; //equal
    node_t curr1, curr2;
    if ((!s1 && s2) || (!s2 && s1))
        res = 0;
    else if (s1 && s2)
    {
        if ((!s1->top && s2->top) || (!s2->top && s1->top))
            res = 0;
        else if (s1->top && s2->top)
        {
            curr1 = s1->top;
            curr2 = s2->top;

            for ( ; curr1 && curr2 && res; curr1 = curr1->next, curr2 = curr2->next)
                if (curr1->ch != curr2->ch)
                    res = 0;
        }
    }

    return res;
}

/**
 * Replace char in str
 * @param s string
 * @param find char to replace
 * @param replace_with new char
 */
void str_replace_char(string_t s, char find, char replace_with)
{
    if (!s)
        return;

    node_t curr = s->top;
    for ( ; curr; curr = curr->next)
        if (curr->ch == find)
            curr->ch = replace_with;
}

/**
 * Destroy string
 * @param s string
 */
void str_destroy(string_t s)
{
    node_t tmp;
    if(s)
    {
        for (; s->top; s->top = tmp) {
            tmp = s->top->next;
            free(s->top);
        }
        free(s);
    }
}

/**
 * Length of string
 * @param s - string
 * @return length
 */
size_t str_len(string_t s)
{
    struct node *head = NULL;
    int len = 0;

    if (s)
    {
        head = s->top;
        for(len = 0; head; head = head->next, len++);
    }
    return len;
}

/**
 * Replace char of string with given index by another char
 * @param s - string
 * @param index - index to replace
 * @param replace_with - new char
 */
void str_edit_by_index(string_t s, int index, char replace_with)
{
    if (!s || !s->top)
        return;

    struct node *tmp = s->top;

    for(int i = 0; i < index && tmp; tmp = tmp->next, i++);

    if (tmp)
        tmp->ch = replace_with;
}