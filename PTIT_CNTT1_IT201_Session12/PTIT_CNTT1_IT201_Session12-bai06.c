//
// Created by FPT on 7/7/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("loi");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *createLinkedList(int n) {
    if (n <=0) {
        printf("loi");
        return NULL;
    }
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        Node *newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head ->prev = newNode;
            head = newNode;
        }
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

void findNode(Node *head,int value) {
    Node *current = head;
    int pos = 1;
    int found = 0;
    while (current != NULL) {
        if (current->data == value) {
            printf("Node %d: %d \n",pos,value);
            found = 1;
        }
        current = current->next;
        pos++;
    }
    if (!found) {
        printf("loi");
    }
}

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    printf("nhap gtri: ");
    Node *head = createLinkedList(n);
    printList(head);

    int value;
    scanf("%d", &value);
    printf("%d\n\n", value);

    findNode(head,value);

    Node* current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

}