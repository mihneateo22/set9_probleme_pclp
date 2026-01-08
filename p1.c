#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* new_node(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->next = NULL;
    return n;
}

void push_back(Node **head, Node **tail, int v) {
    Node *n = new_node(v);
    if (*head == NULL) {
        *head = *tail = n;
    } else {
        (*tail)->next = n;
        *tail = n;
    }
}

void print_list(Node *head) {
    for (Node *p = head; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    printf("\n");
}

void remove_even(Node **head) {
    Node **pp = head;
    while (*pp != NULL) {
        Node *cur = *pp;
        if (cur->val % 2 == 0) {
            *pp = cur->next;
            free(cur);
        } else {
            pp = &cur->next;
        }
    }
}

void free_list(Node *head) {
    while (head != NULL) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node *head = NULL, *tail = NULL;

    int n;
    printf("Cate numere? ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Introdu %d numere: ", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push_back(&head, &tail, x);
    }

    printf("Lista initiala: ");
    print_list(head);

    remove_even(&head);

    printf("Dupa stergerea celor pare: ");
    print_list(head);

    free_list(head);
    return 0;
}
