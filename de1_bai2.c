#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char action;
    char value;
} Operation;

typedef struct {
    Operation data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, Operation op) {
    if (!isFull(s)) {
        s->data[++(s->top)] = op;
    }
}

Operation pop(Stack* s) {
    Operation op = {' ', ' '};
    if (!isEmpty(s)) {
        op = s->data[(s->top)--];
    }
    return op;
}

int main() {
    char text[MAX] = "";
    Stack undoStack, redoStack;
    initStack(&undoStack);
    initStack(&redoStack);

    int choice;
    char ch;

    do {
        printf("\n======================== TEXT EDITOR ========================\n");
        printf("1. DRAW\n");
        printf("2. UNDO\n");
        printf("3. REDO\n");
        printf("4. HIEN THI\n");
        printf("5. THOAT\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap ky tu can chen: ");
                scanf(" %c", &ch);
                {
                    int len = strlen(text);
                    text[len] = ch;
                    text[len + 1] = '\0';
                    Operation op = {'I', ch};
                    push(&undoStack, op);
                    initStack(&redoStack);
                }
                break;

            case 2:
                if (!isEmpty(&undoStack)) {
                    Operation last = pop(&undoStack);
                    if (last.action == 'I') {
                        int len = strlen(text);
                        if (len > 0) {
                            text[len - 1] = '\0';
                            push(&redoStack, last);
                        }
                    }
                } else {
                    printf("Khong co thao tac nao de UNDO.\n");
                }
                break;

            case 3:
                if (!isEmpty(&redoStack)) {
                    Operation last = pop(&redoStack);
                    if (last.action == 'I') {
                        int len = strlen(text);
                        text[len] = last.value;
                        text[len + 1] = '\0';
                        push(&undoStack, last);
                    }
                } else {
                    printf("Khong co thao tac nao de REDO.\n");
                }
                break;

            case 4:
                printf("Van ban hien tai: %s\n", text);
                break;

            case 5:
                printf("Ket thuc chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Moi nhap lai.\n");
        }
    } while (choice != 5);

    return 0;
}
