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

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("loi");
        return -1;
    }
    return stack->arr[stack->top--];
}

char peek(struct Stack *stack) {
    if (stack->top == -1) return "\0";
        return stack->arr[stack->top];
    }

bool isMatching(char open, char close) {
    return (open == '(' &&close == ')'|| (open == '['&&close == ']') || (open == '{'&&close == '}')|| open == '{'&&close == '}');
}
bool isBracketValid(char *expr) {
    int length = strlen(expr);
    struct Stack *stack = createStack(length);

    for (int i = 0; i < length; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(stack,ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            char top = pop(stack);
            if (!isMatching(top, ch)) {
                free(stack->arr);
                free(stack);
                return false;
            }
        }
    }
    bool result = (stack->top == -1);
    free(stack->arr);
    free(stack);
    return result;
}
int main() {
   char expr[1000];

    printf("nhap bieu thuc");
    fgets(expr,sizeof(expr),stdin);
    expr[strcspn(expr,"\n")] = '\0';

    if (isBracketValid(expr)) {
        printf("true");
    }else {
        printf("false");
    }


    return 0;
}