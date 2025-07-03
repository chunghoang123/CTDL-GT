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
        printf("loi");
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
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node *deleteNode(Node *head) {
    if (head ==NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return  NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);;
    temp->next = NULL;
    return head;


}

Node *freeNode(Node *head) {
    Node *temp = head;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);

    }
}


int main() {
    Node *head = createList();
    printList(head);
    head = deleteNode(head);
    printList(head);
    freeNode(head);




    return 0;
}