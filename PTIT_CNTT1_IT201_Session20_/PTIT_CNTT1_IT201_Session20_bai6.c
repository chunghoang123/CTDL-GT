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
int search(Node *root,int n,int level) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == n) {
        return level;
    }
    int left = search(root->left,n,level+1);
    if (left != -1) {
        return left;
    }
    return search(root->right,n,level+1);
}


int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int searchTree = 3;
    int level = search(root,searchTree,0);
    if(level != -1) {
        printf("level: %d\n",level);
    }else {
        printf("error");
    }





    return 0;
}
