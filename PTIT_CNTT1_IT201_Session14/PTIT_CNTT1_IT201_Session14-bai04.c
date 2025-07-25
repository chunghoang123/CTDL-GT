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


int pop(Stack *stack) {
    if (stack->top == NULL)
        return -1;
    Node *temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}


int main() {

    Stack *stack = createStack();

    for (int i = 5; i >= 1; i--) {
        Node *newNode = createNode(i);
        newNode->next = stack->top;
        stack->top = newNode;
    }
    printf("Stack ban dau\n");
    printfStack(stack);
    int popValue = pop(stack);
    if (popValue == -1) {
        printf("gia tri lay ra khoi ngan xep : %d\n",popValue);
    }
    printf("Stack sau khi pop\n");

    printfStack(stack);
    while (pop(stack) != -1);

    printf("Stack sau khi lam rong\n");
    printfStack(stack);
    pop(stack);


    free(stack);


    return 0;
}
