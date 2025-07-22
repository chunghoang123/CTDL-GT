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
int countTree(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countTree(root->left) + countTree(root->right);
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
    int count = countTree(root);

    printf("Number of leaves: %d \n",count);





    return 0;
}
