#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char cuv[15];
    struct Node *next;
} Node;

void deallocate(Node **head);
void insert_end(Node **head, char new_cuv[15]);
void print_list(Node **head);
void iterating_sentence(Node **head, char prop[256]);

int main()
{
    Node *head = NULL;
    unsigned int n, i;
    char word[15], prop[256] = "";
    printf("introduceti numarul de cuvinte : ");
    scanf("%u", &n);
    getchar();
    for(i = 0; i < n; i++)
    {
        printf("introduceti cuvantul %u : ", i + 1);
        fgets(word, 15, stdin);
        word[strcspn(word, "\n")] = '\0';
        insert_end(&head, word);
    }
    // print_list(&head);
    iterating_sentence(&head, prop);
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

void insert_end(Node **head, char new_cuv[15])
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);

    strcpy(new_node->cuv, new_cuv);
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

void print_list(Node **head)
{
    Node *curr = *head;
    unsigned int i = 1;
    while(curr != NULL)
    {
        printf("cuvantul %u : ", i);
        puts(curr->cuv);
        i++;
        curr = curr->next;
    }
}

void iterating_sentence(Node **head, char prop[256])
{
    Node *curr = *head;
    while(curr != NULL)
    {
        strcat(prop, curr->cuv);
        strcat(prop, " ");
        curr = curr->next;
    }
    printf("%s\n", prop);
}