#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insert_beginning(Node **head, int new_value);
void deallocate(Node **head);

int main()
{
    Node *head = NULL;
    unsigned int i = 0;
    insert_beginning(&head, 3);
    insert_beginning(&head, 7);
    for(Node *curr = head; curr != NULL; curr = curr->next)
    {
        i++;
        printf("elementul %u : %d\n", i, curr->value);
    }
    deallocate(&head);
    return 0;
}

void insert_beginning(Node **head, int new_value)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);
    new_node->value = new_value;
    new_node->next = *head;
    *head = new_node;
}

void deallocate(Node **head)
{
    Node *curr = *head;
    while(curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}
