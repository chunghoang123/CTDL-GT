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
    if (newNode == NULL) {
        printf("error");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Node *createList() {
    Node *head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);
    // head->next->next->next->next->next = createNode(6);
    return head;
}


void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node *addNode(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
Node *findNode(Node *head) {
    if (head ==NULL) {
        return NULL;
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    int min = (count % 2 == 0) ? (count /2): (count /2);
    temp = head;
    for (int i = 0; i < min; i++) {
        temp = temp->next;
    }
    return temp;
}
void freeNode(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = createList();
    printList(head);
    Node *min = findNode(head);
    if (min != NULL) {
        int pos = (5%2 == 0)?(5/2)+1:(5+1)/2;
        printf("Node %d: %d\n", pos,min->data);
    }

    head = addNode(head, 6);
    printList(head);
    min = findNode(head);
    if (min != NULL) {
        int pos = (6%2 == 0)?(6/2)+1:(6+1)/2;
        printf("Node %d: %d\n", pos,min->data);
    }
    freeNode(head);



    return 0;
}