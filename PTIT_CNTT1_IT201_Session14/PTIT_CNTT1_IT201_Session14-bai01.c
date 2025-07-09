#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node*createNode(int data) {
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack {
    Node *top;
}Stack;


Stack *createStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}



int main() {
    Stack *mStack = createStack();

    if (mStack->top == NULL) {
        printf("thanh cong");
    }

    free(mStack);


    return 0;
}