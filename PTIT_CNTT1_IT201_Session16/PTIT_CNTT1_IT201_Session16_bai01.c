//
// Created by FPT on 7/13/2025.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;


typedef struct {
    int arr[100];
    int front;
    int rear;
}Queue;


Queue *innitqueue () {
    Queue *q = (Queue *) malloc (sizeof (Queue));
    if (q) {
        q->front = NULL;
        q->rear = NULL;

    }
    return q;
}

int main() {
    Queue *q = innitqueue ();
    if ( q->front == NULL && q->rear == NULL) {
        printf("loi");
    }else {
        printf("khoi tao that bai");
    }
    return 0;
}
