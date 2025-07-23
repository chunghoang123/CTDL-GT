//
// Created by FPT on 7/23/2025.
//
#include<stdio.h>

void initGrapg(int graph[][3],int size) {
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            graph[i][j]=0;
        }
    }
}
void add(int graph[][3],int startNode,int endNode) {
    int u =startNode-1;
    int v =endNode-1;
    if(u>=0 && u<= 3&&v>=0 && v<= 3) {
        graph[u][v]=1;
    }
}
void display(int graph[][3],int size) {
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            printf("%d ",graph[i][j]);

        }
        printf("\n");
    }
}
int main() {
    int graph[3][3];
    int size = 3;
    initGrapg(graph,size);
    display(graph,size);
    add(graph,2,3);
    printf("sau khi them\n");
    display(graph,size);
}