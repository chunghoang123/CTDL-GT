//
// Created by FPT on 7/23/2025.
//
#include<stdio.h>

void initGrapg(int graph[][3],int rows,int cols) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            graph[i][j]=0;
        }
    }
}
void add(int graph[][3],int firstNode,int secondNode) {
    int u = firstNode -1;
    int v = secondNode -1;
    if (u>=0 && u<3 && v>=0 && v<3) {
        graph[u][v]=1;
        graph[v][u]=1;
    }
}
void display(int graph[][3],int rows,int cols) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[3][3];
    initGrapg(graph,3,3);
    display(graph,3,3);
    add(graph,1,2);
    printf("sau khi them\n");
    display(graph,3,3);
}