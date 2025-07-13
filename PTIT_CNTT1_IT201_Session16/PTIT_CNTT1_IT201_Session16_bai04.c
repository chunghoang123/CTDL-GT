

#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
}Queue;


Queue *initqueue () {
    Queue *q= (Queue *) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Node *createNode() {
    Node *newNode = (Node *) malloc(sizeof(Node));
    printf("nhap gitr: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    return newNode;


}

void enqueue (Queue *q) {
    Node *newNode = createNode();
    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("da them %d vao hang doi \n",newNode->data);
}

void display (Queue *q) {
    printf("Queue = {front->");
    Node *current = q->front;
    while (current != NULL) {
        printf("%d ",current->data);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("->NULL\n");
    if (q->rear!=NULL) {
        printf("rear->%d->NULL }\n",q->rear->data);
    }else {
        printf(",rear->NULL }");
    }

}

void peek (Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
    }else{
        printf("%d\n",q->front->data);
    }
}



int main() {

    Queue *q = initqueue ();
    display (q);
    peek (q);

    enqueue (q);
    enqueue (q);
    display (q);
    peek (q);




    return 0;
}