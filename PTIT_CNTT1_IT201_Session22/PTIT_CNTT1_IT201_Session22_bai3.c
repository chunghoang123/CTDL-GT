//
// Created by FPT on 7/24/2025.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *adjList[MAX];

int n;
 Node *createNode(int data) {
     Node *newNode = (Node *)malloc(sizeof(Node));
     newNode->data = data;
     newNode->next = NULL;
     return newNode;
 }
void addEdge( int u, int v) {
     Node *newNode = createNode( v);
     newNode->next = adjList[u];
     adjList[u] = newNode;
 }

void printAdjList() {
     for (int i = 0; i < n; i++) {
         printf("%d: ",i);
         Node *temp = adjList[i];
         while (temp != NULL) {
             printf("%d -> ",temp->data);
             temp = temp->next;
         }
         printf("\n");
     }
 }

int main() {
     int matrix[MAX][MAX];
     printf("nhap so dinh: ");
     scanf("%d",&n);

     for (int i = 0; i < n; i++) {
         adjList[i] = NULL;
     }
     printf("nhap ma tran ke %dx%d:\n ",n,n);
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             scanf("%d",&matrix[i][j]);
         }
     }
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             if (matrix[i][j] == 1) {
                 addEdge(i,j);
             }
         }
     }
     printf("danh sach ke");
     printAdjList();
     return 0;
 }