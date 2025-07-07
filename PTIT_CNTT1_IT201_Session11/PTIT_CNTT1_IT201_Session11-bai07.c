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
        }else {
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


Node* posNode(Node *head, int data, int position) {
    if (position == 1) {
        Node *newNode = createNode(data);
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    Node *current = head;
    int currentPosition = 1;
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("vi tri ko hop le\n");
        return head;
    }

    Node *newNode = createNode(data);
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;

    return head;
}



int main() {
    Node *head = createLinkedList();

    printLinkedList(head);

    int value,positon;
    scanf("%d", &value);
    scanf("%d", &positon);
    printf("value: %d\n", value);
    printf("positon: %d\n", positon);

    head = posNode(head,value,positon);
    printLinkedList(head);

    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }




    return 0;
}