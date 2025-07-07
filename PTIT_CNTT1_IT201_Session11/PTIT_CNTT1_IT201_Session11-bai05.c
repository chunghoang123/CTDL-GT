//
// Created by FPT on 7/7/2025.
//
#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("loi");
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *createLinkedList() {
    int value[]  = {1,2,3,4,5};
    Node *head = NULL;
    Node *tail  = NULL;

    for (int i = 0; i < 5; i++) {
        Node *newNode = createNode(value[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }
    return head;
}


void printLinkedList(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        if (current->next != NULL) {
            printf("<->");
        }
        current = current->next;
    }
    printf("->NULL\n");
}

Node *insertNode(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}




int main() {
    Node *head = createLinkedList();
    printLinkedList(head);

    int value;
    printf("nhap so: ");
    scanf("%d", &value);


    head = insertNode(head, value);
    printLinkedList(head);

    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);

    }



    return 0;
}