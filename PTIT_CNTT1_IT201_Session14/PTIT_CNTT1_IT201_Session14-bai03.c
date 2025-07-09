//
// Created by FPT on 7/9/2025.
//
#include<stdio.h>
#include <stdlib.h>

typedef struct Node {

    int data;
    struct Node *next;
}Node;


Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack {
    Node *top;
}Stack;

Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack *stack) {
    int value;
    printf("nhap so nguyen: ");
    scanf("%d", &value);

    if(value<=0) {
        printf("loi");
        return;
    }
    Node *newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}


void printfStack(Stack *stack) {
    Node *current = stack->top;
    printf("stack = ");
    if (current == NULL) {
        printf("NULL\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->next != NULL)
            printf("->");

        current = current->next;

    }
    printf("->NULL\n");

}

void traveStack(Stack *stack) {
    if (stack->top == NULL) {
        return;
    }
    Node *current = stack->top;
    printf("duyet ngan xep\n");
    while (current != NULL) {
        printf("%d \n", current->data);
        current = current->next;
    }
}


int main() {

    Stack *stack = createStack();

    printf("Stack ban dau\n");
    printfStack(stack);

    push(stack);
    push(stack);
    push(stack);
    push(stack);
    push(stack);

    printf("stack sau khi them ptu\n");
    printfStack(stack);

    traveStack(stack);


    Node*temp;
    while (stack->top != NULL) {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);


    return 0;
}
