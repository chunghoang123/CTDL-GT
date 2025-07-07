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
        printf("erro");
        exit(11);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *createList() {
    int value[] = {10,20,40,50,60};
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


void printList(Node *head) {
    Node *current = head;
    printf("danh sach");
    while (current != NULL) {
        printf(" %d", current->data);
        current = current->next;
    }
    printf("\n");
}


int main() {
    Node *head = createList();
    printList(head);
    Node *current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}