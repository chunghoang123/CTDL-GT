#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *createNode (int data) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("loi");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createLinkedList () {
    Node* head = createNode (10);
    head->next = createNode (20);
    head->next->next = createNode (30);
    head->next->next->next = createNode (40);
    head->next->next->next->next = createNode (50);

    return head;
}


void printLinkedList (Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


 int main() {
    Node *head = createLinkedList ();
    printf("danh sach\n");
    printLinkedList (head);

    Node *temp = createLinkedList ();
    Node *next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }





     return 0;
 }