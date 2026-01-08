#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insert_end(Node **head, int new_value) 
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);
    new_node->next = NULL;
    new_node->value = new_value;

    // the case with no nodes
    if(*head == NULL) 
    // if the list is empty, this will be the first node, after that, if you call the function multiple times, this if would practically not exist and it would jump straight to the line 26
    {
        *head = new_node;
        return;
    }

    Node *curr = *head;
    while(curr->next != NULL) // i want to end up with the last node != NULL after the loop
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

int main()
{
    // the case with no nodes
    Node *head = NULL;
    unsigned int i = 0;
    // Node *head = malloc(sizeof(Node));
    // unsigned int i = 0;
    // if(head == NULL)
    //     exit(2);
    // head->value = 1;
    // head->next = NULL;
    insert_end(&head, 2);
    insert_end(&head, 3);
    for(Node *curr = head; curr != NULL; curr = curr->next)
    {
        i++;
        printf("elementul %u : %d\n", i, curr->value);
    }
    free(head);
    return 0;
}