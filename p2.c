#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char name[20];
    unsigned int age;
    struct Node *next;
} Node;

void search_george(Node **head);
void insert_beginning(Node **head, unsigned int new_age, char new_name[20]);
void insert_end(Node **head, unsigned int new_age, char new_name[20]);
void print_list(Node **head);

int main()
{
    Node *head = NULL;
    unsigned int n, i;
    insert_end(&head, 19, "George");
    insert_end(&head, 21, "Mihai");
    insert_end(&head, 19, "George");
    insert_end(&head, 17, "Radu");
    // print_list(&head);
    search_george(&head);
    return 0;
}

void insert_beginning(Node **head, unsigned int new_age, char new_name[20])
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);
    new_node->age = new_age;
    strcpy(new_node->name, new_name);
    new_node->next = *head;
    *head = new_node;
}

void insert_end(Node **head, unsigned int new_age, char new_name[20])
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(2);
    new_node->age = new_age;
    strcpy(new_node->name, new_name);
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
    new_node->next = NULL;
}

void search_george(Node **head)
{
    Node *curr = *head;
    unsigned int flag = 0;
    while(curr->next != NULL)
    {
        if(strcmp(curr->name, "George") == 0 && curr->age == 19)
        {
            flag = 1;
            if(curr->next->age < curr->age)
            {
                printf("persoana %s este mai tanara decat George.\n", curr->next->name);
                return ;
            }
        }
        curr = curr->next;
    }
    if((flag == 0) && strcmp(curr->name, "George") == 0 && curr->age == 19)
    {
        flag = 1;
        printf("George este ultima persoana din lista. Nu mai exista alte persoane dupa el.\n");
    }
    if(flag == 0)
        printf("George, 19 ani nu apartine listei.\n");
}

void print_list(Node **head)
{
    Node *curr = *head;
    unsigned int i = 1;
    while(curr != NULL)
    {
        printf("persoana %u : \n", i);
        printf("nume : %s", curr->name);
        printf("\nvarsta : %u\n\n", curr->age);
        i++;
        curr = curr->next;
    }
}