//
// Created by FPT on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


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
bool isPalindrome(char *str) {
    int length = strlen(str);
    struct Stack *stack = createStack(length);
    for (int i = 0; i < length; i++) {
        push(stack,str[i]);
    }
    for (int i = 0; i < length; i++) {
        if (str[i] != pop(stack)) {
            free(stack->arr);
            free(stack);
            return false;
        }
    }
    free(stack->arr);
    free(stack);
    return true;
}
int main() {
    char str[100];

    printf("nhap chuoi");
    fgets(str,sizeof(str),stdin);

    str[strcspn(str,"\n")] = '\0';

    if (isPalindrome(str)) {
        printf("true");
    }else {
        printf("false");
    }



    return 0;
}