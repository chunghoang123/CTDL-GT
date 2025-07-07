//
// Created by FPT on 7/7/2025.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("loi");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *createLinkedList() {
    int value[] = {1,2,3,4,5};
    Node *head = NULL;
    Node *tail = NULL;


    for (int i = 0; i < 5; i++) {
        Node *newNode = createNode(value[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
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
Node *deleteNode (Node *head,int position) {
    if (head == NULL) {
        printf("loi");
        return NULL;
    }
    if (position == 1) {
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    Node *current = head;
    int currentPosition = 1;
    while (current != NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("loi");
        return head;
    }
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    return head;
}



int main() {
    Node *head = createLinkedList();
    printLinkedList(head);

    int position;
    scanf("%d", &position);
    head = deleteNode(head,position);
    printLinkedList(head);

    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }



    return 0;
}