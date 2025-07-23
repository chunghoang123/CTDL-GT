//
// Created by FPT on 7/23/2025.
//
#include<stdio.h>

void initGrapg(int graph[][4],int size) {
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            graph[i][j]=0;
        }
    }
}
void add(int graph[][4],int firstNode,int secondNode) {
    if(firstNode>=0 && firstNode<= 4&&secondNode>=0 && secondNode<= 4) {
        graph[firstNode][secondNode]=1;
        graph[secondNode][firstNode]=1;
    }
}
void display(int graph[][4],int size) {
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[4][4];
    int size = 4;
    initGrapg(graph,size);
    display(graph,size);
    add(graph,0,1);
    add(graph,0,2);
    add(graph,1,2);
    add(graph,2,3);
    printf("sau khi them\n");
    display(graph,size);
}