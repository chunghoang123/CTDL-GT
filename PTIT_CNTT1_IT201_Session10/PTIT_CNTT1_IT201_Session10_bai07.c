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
Node *insertionSort(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *sor = NULL;
    Node *temp = head;
    while (temp != NULL) {
        Node *next = temp->next;

        if (sor == NULL|| sor->data >= temp->data) {
            temp->next = sor;
            sor = temp;
        }else {
            Node *current = sor;
            while (current->next != NULL && current->next->data < current->data) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
        temp = next;
    }
    return sor;

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
    head = insertionSort(head);
    printList(head);
    freeNode(head);

    return 0;
}