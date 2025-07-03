//
// Created by FPT on 7/3/2025.
//
#include <stdio.h>

#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("loi\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *createList() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    return head;
}
void printList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        printf("dara:%d \n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    Node *head = createList();
    printList(head);

    Node *temp = createList(head);
    Node *next;




    return 0;
}