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
Node *createNode() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    int n;
    printf("nhap n:");
    scanf("%d",&n);
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void display(Node *node) {
    printf("node = {");
    printf("data:%d ,",node->data);
    printf("left->NULL,");
    printf("right->NULL,");
    printf("}");
}

int main() {
    Node *newNode = createNode();
    display(newNode);




    return 0;
}
