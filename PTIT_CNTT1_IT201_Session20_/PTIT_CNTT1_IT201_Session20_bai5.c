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
int findMax(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int lMax = findMax(root->left);
    int rMax = findMax(root->right);
    int max  = root->data;
    if (lMax > max) {
        max = lMax;
    }
    if (rMax > max) {
        max = rMax;
    }
    return max;
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
    int max = findMax(root);
    printf("max: %d \n",max);





    return 0;
}
