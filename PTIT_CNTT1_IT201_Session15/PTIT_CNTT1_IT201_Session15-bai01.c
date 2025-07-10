#include <stdio.h>


#define MAX 100
typedef struct {
    int data[MAX];
    int front;
    int rear;
    int sizeMax;

}Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->sizeMax = MAX;
}



int main() {
    Queue queue;
    Queue* q = &queue;
    initQueue(q);

    printf("front = %d\n",q->front);
    printf("rear = %d\n",q->rear);
    printf("sizeMax = %d\n",q->sizeMax);




    return 0;
}