//
// Created by FPT on 7/21/2025.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;

}Node;

Node *createNode(int n) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void add(Node *root, int n) {
    if (root == NULL) {
        return;
    }

    Node *queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node *temp = queue[front++];
        if (temp->left == NULL) {
            temp->left = createNode(n);
            return;

        }else {
            queue[rear++] = temp->left;
        }
        if (temp->right == NULL) {
            temp->right = createNode(n);
            return;

        }else {
            queue[rear++] = temp->right;
        }

    }
}

void levelorder(Node *root) {
    if (root == NULL) return;

    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node *temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}
int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("trc khi them ");
    levelorder(root);

    add(root, 8);
    printf("\nsau khi them ");
    levelorder(root);



    return 0;
}
