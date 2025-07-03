//
// Created by FPT on 7/3/2025.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("loi");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createList() {
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
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


Node *addNode(Node *head, int data) {
    Node *newNode = createNode(data);
    if(head == NULL) {
        return newNode;
    }
    Node *current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
void freeNode(Node *head) {
    Node *temp ;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    Node *head = createList();
    printList(head);
    int value;
    scanf("%d", &value);
    if(value < 0) {
        printf("loi");
        freeNode(head);
        return 1;
    }
    head = addNode(head, value);
    printList(head);
    freeNode(head);



    return 0;
}