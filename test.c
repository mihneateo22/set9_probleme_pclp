#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insert_end(Node **head, int new_value);

int main()
{
    Node *head = NULL;
    unsigned int i = 0;
    insert_end(&head, 1);
    insert_end(&head, 3);
    for(Node *curr = head; curr != NULL; curr = curr->next)
    {
        i++;
        printf("elementul %u : %d\n", i, curr->value);
    }
    return 0;
}

void insert_end(Node **head, int new_value)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);
    new_node->value = new_value;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return ;
    }

    Node *curr = *head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}