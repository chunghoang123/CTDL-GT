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

void push(struct Stack *stack, int data) {
    if (stack->top == stack->capacity - 1) {
        printf("loi");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("loi");
        return -1;
    }
    return stack->arr[stack->top--];
}
void daoStack(int *arr,int n) {
    struct Stack *stack = createStack(n);
    for (int i = 0; i < n; i++) {
        push(stack,arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(stack);
    }
    free(stack->arr);
    free(stack);

}
void printArr(int *arr,int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
        if (i < n-1) {
            printf(",");
        }
    }
        printf("]\n");

}

int main() {
   int n;
    printf("nhap n: ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("nhap arr\n ");
    for (int i = 0; i < n; i++) {
        printf("nhap arr[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("mang ban dau");
    printArr(arr,n);

    daoStack(arr,n);
    printf("mang dao nguoc");
    printArr(arr,n);

    free(arr);

    return 0;
}