#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("loi\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *createLinkedList() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    return head;
}

void printLinkedList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("->NULL\n");
}

int countNodes(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next; // Cập nhật temp để di chuyển đến node tiếp theo
    }
    return count;
}

int main() {
    Node *head = createLinkedList();
    printLinkedList(head);
    int count = countNodes(head);
    printf("danh sach liet ke co %d ptu\n", count);

    Node *temp = head;
    Node *next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}