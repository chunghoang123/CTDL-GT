//
// Created by FPT on 7/10/2025.
//
#include <stdio.h>


typedef struct {
    int data[100];
    int front;
    int rear;
    int cap;
}Queue;


void initQueue(Queue* q,int cap) {
    q->front = 0;
    q->rear = -1;
    q->cap = cap;

}

void displayQueue(Queue* q) {
    printf("\n");
    for (int i = q->front;i<= q->rear;i++) {
        printf("%d ",q->data[i]);
    }
    printf("\n");
    printf("front = %d\n",q->front);
    printf("rear = %d\n",q->rear);
    printf("cap = %d\n",q->cap);
}

int isEmptyQueue(Queue* q) {
    return q->rear < q->front;
}


int main() {
    Queue q1,q2;
    initQueue(&q1,5);
    displayQueue(&q1);
    if (isEmptyQueue(&q1)) {
        printf("true");
    }else {
        printf("false");
    }

    initQueue(&q2,5);
    q2.rear = 2;
    q2.data[0] = 5;
    q2.data[1] = 6;
    q2.data[2] = 7;
    displayQueue(&q2);


    if (isEmptyQueue(&q2)) {
        printf("true");
    }
    else {
        printf("false");
    }





    return 0;
}
