//
// Created by FPT on 7/24/2025.
//
#include<stdio.h>
#define MAX 100

void initGraph(int graph[MAX][MAX],int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            graph[i][j]=0;
        }
    }
}
void addEdge(int graph[MAX][MAX],int u,int v) {
    graph[u][v]=1;
    graph[v][u]=1;
}

void printGraph(int graph[MAX][MAX],int n) {
    printf("Ma tran ke cau do thi\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[MAX][MAX];
    int n;
    scanf("%d",&n);
    initGraph(graph,n);
    printf("nhap canh u_v\n");
    while (1) {
        int u,v;
        scanf(" %d %d",&u,&v);
        if (u==-1&&v==-1) {
            break;
        }
        if (u>=0&&u<n ||v>=0 &&v<n) {
            addEdge(graph,u,v);
        }else {
            printf("dinh ko hop le");
        }
    }
    printGraph(graph,n);

    return 0;



}