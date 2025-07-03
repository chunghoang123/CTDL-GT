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
    head->next->next->next->next->next = createNode(5);
    return head;
}


void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node *deleteList(Node *head,int data) {
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL && current->data == data) {
        head  = current->next;
        free(current);
        current = head;
    }

    while (current != NULL) {
        if (current->data == data) {
            prev->next = current->next;
            free(current);
            current = prev;
        }else {
            prev = current;
            current = current->next;

        }

    }
    return head;

}


void freeNode(Node *head) {
    Node *current;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}


int main() {
    Node *head = createList();
    printList(head);

    int n;
    scanf("%d", &n);
    if (n <= 0) {
        printf("error");
        freeNode(head);
        return 1;
    }

    head = deleteList(head,n);

    printList(head);
    freeNode(head);





    return 0;
}