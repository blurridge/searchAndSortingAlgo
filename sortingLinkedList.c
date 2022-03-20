#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

    char phone[15];
    char name[25];
    struct node *next;
} NODE, *LL;

void printChoices();
NODE *createNode();
void assignData(NODE **newNode, char data[], char person[]);
void insertNode(NODE *newNode, LL *head);
// void sortList(LL *currentList);
void printList(LL head);

int main(){

    NODE *new;
    LL head = NULL;
    int choice;
    char name[25], phone[15];
    while(1)
    {
        printChoices();
        scanf("%d", &choice);
        if(choice == 1)
        {
            new = createNode();
            printf("Enter a name: ");
            scanf(" %[^\n]s", name);
            printf("Enter phone number: ");
            scanf(" %[^\n]s", phone);
            assignData(&new, phone, name);
            insertNode(new, &head);
        }

        if(choice == 2)
            printList(head);

        // if(choice == 3)
        // {
        //     printf("Before sorting: \n");
        //     printList(head);
        //     sortList(head);
        //     printf("After sorting: \n");
        //     printList(head);
        // }
    }

    return 0;
}

void printChoices(){

    printf("1. Append\n");
    printf("2. Browse\n");
    printf("3. Sort\n");
    printf("Enter your choice: ");
}

NODE *createNode(){

    NODE *newNode = malloc(sizeof(NODE));
    if(newNode == NULL)
        printf("Not enough memory!\n");
    return newNode;
}

void assignData(NODE **newNode, char data[], char person[]){

    strcpy((*newNode)->name, person);
    strcpy((*newNode)->phone, data);
}

void insertNode(NODE *newNode, LL *head){

    newNode->next = *head;
    *head = newNode;
    printf("Successfully inserted node!\n");
}

void printList(LL head){

    NODE *trav = head;
    for(; trav != NULL; trav = trav->next)
        printf("%s %s\n", trav->name, trav->phone);
}