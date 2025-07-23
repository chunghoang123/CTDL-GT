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
void add(int graph[][3],int node1,int node2) {
  if(node1>=0 && node1<= 3&&node2>=0 && node2<= 3) {
    graph[node1][node2]=1;
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
  add(graph,1,0);
  add(graph,1,2);
  add(graph,2,0);


  printf("sau khi them\n");
  display(graph,size);
}