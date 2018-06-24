#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people
{
    size_t size;
    size_t size2;
    char *name;
    char *adress;
    char phone[15];
}
people;

// You can insert new people usig this
people* insert(people *person, char *name, char *adress, char phone[], int i)
{
    people* new_person=(people*)realloc(person, (i+1)*sizeof(people));
    if (new_person)
    {
        size_t size = strlen(name)*sizeof(char);
        new_person[i].size = size;
        new_person[i].name = malloc(size +1);
        strcpy(new_person[i].name, name);

        size_t size2 = strlen(adress)*sizeof(char);
        new_person[i].size = size2;
        new_person[i].adress = malloc(size2 +1);
        strcpy(new_person[i].adress, adress);

        strcpy(new_person[i].phone, phone);
    }
    return (new_person);
}

int main()
{
    FILE *f;
    f = fopen("data.txt", "w");

    people *person = NULL;

    int count = 0;
    int amount;

    char name[15];
    char adress[15];
    char phone[15];

    printf("how many people you want?");
    scanf("%d", &amount);

    printf("input name adress phone_number:\n");
    while (count < amount)
    {
        scanf("%s %s %s", name, adress, phone);
        people* new_person = insert(person, name, adress, phone, count);
        if (new_person)
        {
            person = new_person;
            fprintf(f, "%s %s %s\n", person[count].name, person[count].adress, person[count].phone);
        }
        else
            break;
        count++;
   }

    for (int k=0; k<count; k++)
    {
        free(person[k].name);
        free(person[k].adress);
    }
    free(person);

    fclose(f);
    return 0;
}
