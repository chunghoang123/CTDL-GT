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
    if(newNode ==NULL) {
        printf("loi");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *createLinkList() {
    int value[] = {1,2,3,4,5};
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < 5; i++) {
        Node *newNode = createNode(value[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }else{}
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    return head;
}
void printList(Node *head) {
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

int search(Node *head, int value) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    Node *head = createLinkList();
    printList(head);

    int value;
    printf("nhap so can tim");
    scanf("%d", &value);


    if (search(head, value)) {
        printf("true");
    } else {
        printf("false");
    }

    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }


    return 0;
}
