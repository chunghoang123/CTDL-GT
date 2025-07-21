//
// Created by FPT on 7/21/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;


Node *createNode(int n) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = n;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

typedef struct Queue {
    Node *trueNode;
    struct Queue *next;
}Queue;

Queue *createQueue(Node *trueNode) {
    Queue *newqueue = (Queue *)malloc(sizeof(Queue));
    newqueue->trueNode = trueNode;
    newqueue->next = NULL;
    return newqueue;
}

bool bfs(Node *root,int n) {
    if (root == NULL) {
        return false;
    }
    Queue *head  = createQueue(root);

    while (head!= NULL) {
        Node *current = head->trueNode;
        Queue *temp = head;
        head = head->next;
        free(temp);

        if (current->data == n) {
            while (head != NULL) {
                temp = head;
                head = head->next;
                free(temp);
            }
            return true;
        }
        if (current->left !=NULL) {
            head =createQueue(current->left);
        }
        if (current->right !=NULL) {
            Queue *newNode = createQueue(current->right);
            if (head == NULL) {
                head = newNode;
            }else {
                Queue *end = head;
                while (end->next != NULL) {
                    end = end->next;
                    end->next = newNode;
                }
            }
        }

    }
    return false;

}
int main(){
Node *root = createNode(2);
root->left = createNode(3);
root->left->left = createNode(5);
root->right = createNode(4);
    int n = 3;

    if (bfs(root,n)) {
        printf("true\n");
    }else {
        printf("false\n");
    }



    return 0;
}
