#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char nume[21];
    int nr_matricol;
    int cod_materie[3];
    float medie_materie[3];
    struct Node *next;
} Node;

void deallocate(Node **head);
void print_list(Node **head);
float medie_student_separat(Node *head);
float medie_grupa(Node **head);
void premiant(Node **head);
void insert_end_then_sort(Node **head);
void remove_element(Node **head);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    char name[21];
    int nrmat, cod_mat[3], numar_materii;
    float medie[3];
    unsigned int i = 0, n, j;
    printf("introduceti numarul de studenti : ");
    scanf("%u", &n);
    printf("\n");
    getchar();
    printf("INTRODUCETI : \n");
    for(i = 0; i < n; i++)
    {
        Node *new_node = malloc(sizeof(Node));
        new_node->next = NULL;
        if(new_node != NULL)
        {
            new_node->next = NULL;
            printf("numele : ");
            fgets(name, 21, stdin);
            name[strcspn(name, "\n")] = '\0';
            strcpy(new_node->nume, name);
            printf("nr matricol : ");
            scanf("%d", &nrmat);
            getchar();
            new_node->nr_matricol = nrmat;
            for(j = 0; j < 3; j++)
            {
                printf("cod materie %u : ", j + 1);
                scanf("%d", &cod_mat[j]);
                getchar();
                new_node->cod_materie[j] = cod_mat[j];
            }
            for(j = 0; j < 3; j++)
            {
                printf("medie materie %u : ", j + 1);
                scanf("%f", &medie[j]);
                getchar();
                new_node->medie_materie[j] = medie[j];
            }
            printf("\n");
            if(head == NULL)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {
                tail->next = new_node;
                tail = new_node;
            }
        }
    }
    printf("media generala a grupei de studenti este : %f\n", medie_grupa(&head));
    printf("\n");
    // premiant(&head);
    insert_end_then_sort(&head);
    remove_element(&head);
    print_list(&head);
    deallocate(&head);
    return 0;
}

float medie_student_separat(Node *head)
{
    float medie_student;
    unsigned int i;
    medie_student = 0.0;
    for(i = 0; i < 3; i++)
        medie_student += head->medie_materie[i];
    medie_student /= 3;
    return medie_student;
}

float medie_grupa(Node **head)
{
    float medie_generala = 0.0, medie_student;
    unsigned int i = 0, noduri_lista = 0;
    Node *curr = *head;
    while(curr != NULL)
    {
        noduri_lista++;
        medie_student = medie_student_separat(curr);
        medie_generala += medie_student;
        curr = curr->next;
    }
    medie_generala /= noduri_lista;
    return medie_generala;
}

void premiant(Node **head)
{
    float medie_max = 0.0, medie_student;
    unsigned int i = 0, max_index = 0;
    Node *curr = *head;
    while(curr != NULL)
    {
        medie_student = medie_student_separat(curr);
        if(medie_student > medie_max)
        {
            medie_max = medie_student;
            max_index = i;
        }
        i++;
        curr = curr->next;
    }

    i = 0;
    curr = *head;
    while(curr != NULL)
    {
        if(i == max_index)
        {
            printf("numele studentului preminat : ");
            puts(curr->nume);
            printf("numarul matricol al studentului premiant : %d\n", curr->nr_matricol);
            break;
        }
        i++;
        curr = curr->next;
    }
}

// intrebare laborator programare : vreau sa mi se clarifice ca este bine

void insert_end_then_sort(Node **head)
{
    char name[21];
    int nr_mat, cod_mat[3];
    float med_mat[3];
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);
    printf("introduceti numele studentului transferat : ");
    fgets(name, 21, stdin);
    name[strcspn(name, "\n")] = '\0';
    strcpy(new_node->nume, name);
    printf("introduceti numarul matricol : ");
    scanf("%d", &nr_mat);
    new_node->nr_matricol = nr_mat;
    getchar();
    for(unsigned int i = 0; i < 3; i++)
    {
        printf("cod materie %u : ", i + 1);
        scanf("%d", &cod_mat[i]);
        new_node->cod_materie[i] = cod_mat[i];
    }
    getchar();
    for(unsigned int i = 0; i < 3; i++)
    {   
        printf("medie materie %u : ", i + 1);
        scanf("%f", &med_mat[i]);
        new_node->medie_materie[i] = med_mat[i];
    }

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

// de aici incepe sortarea, pana aici era bagat la coada

    if(strcmp(curr->nume, new_node->nume) < 0)
        return;

    curr->next = NULL;
    curr = *head;
    if(strcmp(curr->nume, new_node->nume) > 0)
    {
        new_node->next = curr;
        *head = new_node;
        return ;
    }
    Node *prev = *head;
    curr = prev->next;
    while(curr != NULL)
    {
        if(strcmp(curr->nume, new_node->nume) > 0)
        {
            new_node->next = curr;
            prev->next = new_node;
            return ;
        }
        prev = prev->next;
        curr = curr->next;
    }
}

void remove_element(Node **head)
{
    if(*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL)
        return ;
    Node *temp = (*head)->next->next;
    (*head)->next->next = temp->next;
    free(temp);
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

void print_list(Node **head)
{
    Node *curr = *head;
    unsigned int i = 0, j;
    printf("AFISAREA LISTEI : \n\n");
    while(curr != NULL)
    {
        i++;
        printf("nume persoana %u : ", i);
        puts(curr->nume);
        printf("numar matricol persoana %u : %d\n", i, curr->nr_matricol);
        for(j = 0; j < 3; j++)
            printf("cod materie %u : %d\n", j + 1, curr->cod_materie[j]);
        for(j = 0; j < 3; j++)
            printf("medie materie %u : %f\n", j + 1, curr->medie_materie[j]);
        printf("\n\n");
        curr = curr->next;
    }
}