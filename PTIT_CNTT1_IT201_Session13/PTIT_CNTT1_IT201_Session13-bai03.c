//
// Created by FPT on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>


struct Stack {
    int *arr;
    int top;
    int capacity;
};


struct Stack *createStack(int maxSize) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = maxSize;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void addStack(struct Stack *stack, int data) {
    if(isFull(stack)) {
        printf("Stack full\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int layptu(struct Stack *stack) {
    if (stack->top == - 1) {
        printf("No element in stack\n");
        return -1;
    }
    return stack->arr[stack->top--];
}
void printfStack(struct Stack *stack) {
    printf("Stack:{ \n");
    printf("elements: [");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ",stack->arr[i]);
        if (i < stack->top) {
            printf(",");
        }
    }
    printf("]\n");
    printf("top:%d\n",stack->top);
    printf("cap: %d\n",stack->capacity);
    printf("}\n");
}
int main() {
    int maxEle = 5;
    struct Stack *stack = createStack(maxEle);

    addStack(stack,1);
    addStack(stack,2);
    addStack(stack,3);
    addStack(stack,4);
    addStack(stack,5);

    printfStack(stack);

    int value = layptu(stack);
    if (value != -1) {
        printf("value is %d\n",value);
    }
    printfStack(stack);

    while (layptu(stack)!= - 1) ;
    printfStack(stack);
    layptu(stack);
    free(stack->arr);
    free(stack);

    return 0;
}