#include <stdio.h>
#include <stdlib.h>


struct Stack {
    int *arr;
    int top;
    int capacity;
};


struct Stack *createStack(int maxSize) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("loi");
        exit(1);
    }
    stack->capacity = maxSize;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    if (stack->arr == NULL) {
        printf("loi");
        free(stack);
        exit(1);

    }
    return stack;
}
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("loi");
    return;
    }
    stack->arr[++stack->top] = data;
    printf("da them %d vao ngan xep\n",data);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("loi");
        return -1;
    }
    return stack->arr[stack->top--];
}
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("loi");
        return -1;
    }
    return stack->arr[stack->top];
}

int size(struct Stack *stack) {
    return stack->top + 1;
}

void freeStack(struct Stack *stack) {
    free(stack->arr);
    free(stack);
}
int main() {
    int maxEle = 5;
    struct Stack *stack = createStack(maxEle);
    printf("ngan xep dc tao vs sl ptu toi da la :%d",stack->capacity);
    printf("ngan xep hien tai %s\n",isEmpty(stack) ? "rong" : "ko rong");

    push(stack,1);
    push(stack,2);
    push(stack,3);

    printf("kich thuoc ngan xep: %d\n",size(stack));
    printf("phan  tu o dinh: %d\n",peek(stack));
    printf("phan tu dc xoa: %d\n ",pop(stack));
    printf("ptu o dinh sau khi xoa: %d",peek(stack));


    push(stack,4);
    push(stack,5);
    push(stack,6);
    while(!isEmpty(stack)) {
        printf("phan tu dc xoa: %d\n",pop(stack));
    }
    pop(stack);
    freeStack(stack);
    return 0;
}