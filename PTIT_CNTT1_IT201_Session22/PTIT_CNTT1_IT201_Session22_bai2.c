//
// Created by FPT on 7/24/2025.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int v;
    struct Node *next;
}Node;

Node *adjList[MAX];

Node * createNode(int v) {
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = NULL;
    return newNode;
}
void initGraph(int n) {
    for (int i=0;i<n;i++) {
        adjList[i] = NULL;
    }
}

void addEdge(int u,int v) {
    Node * newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void printGraph(int n) {
    printf("danh sach ke cua do thi\n");
    for (int i=0;i<n;i++) {
        printf("%d: ",i);
        Node * temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ",temp->v);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n;
    scanf("%d",&n);
    initGraph(n);
    printf("nhap canh u v");
    while (1) {
        int u,v;
        scanf(" %d %d",&u,&v);
        if (u==-1&&v==-1) {
            break;
        }
        if (u >= 0 && u < n && v >= 0 && v < n)
            addEdge(u, v);
        else
            printf("Canh khong hop le!\n");
    }
    printGraph(n);
    return 0;
    }
