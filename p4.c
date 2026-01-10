#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void deallocate(Node **head);
void print_list(Node *head);
void insert_after(Node *node, int new_value);
void insert_beginning(Node **head, int new_value);
void delete_condition(Node **head);
void insert_after_4th(Node **head); // b)
void insert_after_14(Node **head); // c)
void insert_before_14(Node **head); // d)

int main()
{
    Node *head = NULL;
    insert_beginning(&head, 6);
    insert_after(head, 5);
    insert_after(head->next, 6);
    insert_after(head->next->next, 8);

    delete_condition(&head); // cerinta initiala

    insert_after(head->next, 14); // inserarea acelui nou element din cerinta pe pozitia a 3 a

    insert_beginning(&head, 22); // a)

    insert_after_4th(&head); // b)

    insert_after_14(&head); // c)

    insert_before_14(&head); // d)

    print_list(head);
    deallocate(&head);
    return 0;
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
    *head = NULL;
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

void insert_after(Node *node, int new_value) 
// nu merge sa faci daca head == NULL (headul din main)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(2);
    new_node->value = new_value;
    new_node->next = node->next;
    node->next = new_node;
}

void print_list(Node *head)
{
    Node *curr = head;
    unsigned int i = 0;
    while(curr != NULL)
    {
        i++;
        printf("ELEMENTUL %u : %d\n", i, curr->value);
        curr = curr->next;
    }
}

void delete_condition(Node **head)
{
    if(*head == NULL)
        return ;

    Node *curr = *head;
    while(curr->next != NULL)
    {
        if(curr->next->value == 6)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else curr = curr->next;
    }
}

void insert_after_4th(Node **head)
{
    Node *curr = *head;
    unsigned int i = 0;
    while(curr != NULL)
    {
        i++;
        curr = curr->next;
    }
    if(i > 4)
        insert_after((*head)->next->next->next, 100);
}

void insert_after_14(Node **head)
{
    Node *curr = *head;
    while(curr != NULL)
    {
        if(curr->value == 14)
            insert_after(curr, 140);
        curr = curr->next;
    }
}

void insert_before_14(Node **head)
{
    Node *curr = *head;

    if(curr->value == 14)
        insert_beginning(head, 1400);

    while(curr->next != NULL)
    {
        if(curr->next->value == 14)
        {
            insert_after(curr, 1400);
            curr = curr->next->next;
        }
        else curr = curr->next;
    }
}