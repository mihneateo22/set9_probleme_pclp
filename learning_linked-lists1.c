#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

int main()
{
    Node head;
    head.value = 1;
    head.next = malloc(sizeof(Node));
    head.next->value = 2;
    head.next->next = malloc(sizeof(Node));
    head.next->next->value = 3;
    head.next->next->next = NULL;

    Node *curr = &head;
    unsigned int i = 1;

    while(curr != NULL)
    {
        printf("elememntul %u : %d\n", i, curr->value);
        //iterating through a linked list using while
        curr = curr->next;
        i++;
    }

    i = 1;
    for(Node *curr = &head; curr != NULL; curr = curr->next)
    {
        printf("elementul %u : %d\n", i, curr->value);
        i++;
    }

    //the memory needs to be freed from the last allocated to the first
    free(head.next->next);
    free(head.next);
    return 0;
}