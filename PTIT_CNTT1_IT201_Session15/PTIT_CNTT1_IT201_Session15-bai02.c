//
// Created by FPT on 7/10/2025.
//
#include <stdio.h>
#define MAX 100



typedef struct {
    int data[MAX];
    int front;
    int rear;
    int cap;
}Queue;

void initQueue(Queue *q,int cap) {
    q->front =0;
    q->rear = -1;
    q->cap = cap;
}
void displayQueue(Queue *q) {
    printf("queue : arr[");
    for (int i = q->front;i<=q->rear;i++) {
        printf("%d ",q->data[i]);
    }
    printf("]\n");
    printf("front = %d\n",q->front);
    printf("rear = %d\n",q->rear);
    printf("sizeMax = %d\n",q->cap);

}
void enqueue(Queue *q,int value) {
    if (q->rear -q->front+1>= q->cap) {
        printf("queue full\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}


int main() {
    Queue queue;
    Queue* q = &queue;
    int cap;
    printf("nhap suc chua ham doi");
    scanf("%d",&cap);
    initQueue(q,cap);
    displayQueue(q);
    for (int i = 0;i<5;i++) {
        int n;
        printf("nhap so nguyen");
        scanf("%d",&n);
        enqueue(q,n);
    }
    displayQueue(q);





    return 0;
}

