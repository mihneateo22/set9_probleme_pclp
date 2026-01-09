#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void deallocate(Node **head);
void insert_sorted(Node **head, int new_value);
void insert_beginning(Node **head, int new_value);
void insert_after(Node *node, int new_value);
void print_list(Node *head);
void remove_element(Node **head);

int main()
{
    Node *head = NULL;
    insert_sorted(&head, 6);
    insert_sorted(&head, 3);
    insert_sorted(&head, 2);
    insert_sorted(&head, 0);
    remove_element(&head);
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

void print_list(Node *head)
{
    Node *curr = head;
    unsigned int i = 0;
    while(curr != NULL)
    {
        i++;
        printf("ELEMNTUL %u : %d\n", i, curr->value);
        curr = curr->next;
    }
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
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(2);
    new_node->value = new_value;
    new_node->next = node->next;
    node->next = new_node;
}

void insert_sorted(Node **head, int new_value)
{
    if(*head == NULL || (*head)->value >= new_value)
    {
        insert_beginning(head, new_value);
        return ;
    }

    Node *curr = *head;
    while(curr->next != NULL)
    {
        if(curr->next->value >= new_value)
            break;
        curr = curr->next;
    }
    insert_after(curr, new_value);
}

void remove_element(Node **head)
{
    if(*head == NULL)
        return ;

    while((*head) != NULL && (*head)->value % 2 == 0)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    if(*head == NULL)
        return ;

    Node *curr = *head;
    while(curr->next != NULL)
    {
        if(curr->next->value % 2 == 0)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else curr = curr->next;
    }
}