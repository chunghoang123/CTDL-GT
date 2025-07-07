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
            head->prev = newNode;
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

Node *deleteNode(Node *head,int value) {
    if (head == NULL) {
        return NULL;
    }
    Node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            Node *temp = current;
            if (current == head) {
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }else {
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            current = current->next;
            free(temp);
        }else {
            current = current->next;
        }
    }
    return head;
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
    head = deleteNode(head, value);
    printList(head);

    Node* current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

}