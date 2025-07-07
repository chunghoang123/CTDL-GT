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
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL) {
        printf("loi");
        exit(1);
    }
    head ->data = data;
    head ->next =NULL;
    head->prev = NULL;
    return head;

}

Node* createLinkedList() {
    int value[] = {1,2,3,4,5};
    Node *head = NULL;
    Node * tail = NULL;
    for (int i=0;i<5;i++) {
        Node* newNode = createNode(value[i]);
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

void printfNode(Node *head) {

    Node* current = head;
    printf("\n");
    int count = 1;
    while (current !=NULL) {
        printf("Node %d: %d\n",count,current->data);
        current = current->next;
        count++;
    }
}


int main() {

    Node *head = createLinkedList();
    printfNode(head);
    Node *current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }





    return 0 ;
}


