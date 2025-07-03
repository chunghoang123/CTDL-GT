#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
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
    return head;
}

void printList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = createList();
    printList(head);

    Node *temp = createList();
    Node *next;
    return 0;
}