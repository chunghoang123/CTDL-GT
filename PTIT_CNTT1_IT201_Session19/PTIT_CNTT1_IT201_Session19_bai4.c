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
void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    preorder(root->left);
    printf("%d \n",root->data);

    preorder(root->right);

}

int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->left->left = createNode(5);
    root->right = createNode(4);
    preorder(root);



    return 0;
}