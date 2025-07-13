

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

void delqueue (Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    printf("%d da xoa ",temp->data);
}
 void print(Queue*q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}


int main() {

    Queue *q = initqueue ();
    display (q);
    delqueue(q);

    enqueue (q);
    enqueue (q);
    enqueue(q);
    display (q);
    peek (q);

    delqueue(q);
    display (q);
    peek (q);

    print(q);




    return 0;
}