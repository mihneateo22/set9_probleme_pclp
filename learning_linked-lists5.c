#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insert_beginning(Node **head, int new_value);
void deallocate(Node **head);
void insert_after(Node *node, int new_value);

int main()
{
    Node *head = NULL;
    unsigned int i = 0;
    insert_beginning(&head, 3);
    insert_beginning(&head, 7);
    insert_beginning(&head, 1);
    insert_beginning(&head, 8);
    insert_after(head, 5);//inserting after the first element in the list
    insert_after(head->next, -1);//inserting after the first element in the list
    insert_after(head->next->next, 0);//inserting after the first element in the list
    for(Node *curr = head; curr != NULL; curr = curr->next)
    {
        i++;
        printf("elementul %u : %d\n", i, curr->value);
    }
    deallocate(&head);
    return 0;
}

void insert_after(Node *node, int new_value)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);
    new_node->value = new_value;
    new_node->next = node->next;
    node->next = new_node;
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
