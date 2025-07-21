//
// Created by FPT on 7/21/2025.
//
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool dfs(Node *root,int n) {
    if (root == NULL) {
        return false   ;
    }
    if (root->data == n) {
        return true;
    }
    return dfs(root->left,n)||dfs(root->right,n);
}

int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->left->left = createNode(5);
    root->right = createNode(4);
    int n = 3;
    if(dfs(root,n)) {
        printf("true\n");
    }else {
        printf("false\n");
    }


    return 0;
}