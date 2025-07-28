//
// Created by FPT on 7/28/2025.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Page {
    char url[100];
    char timestamp[100];
    struct Page* next;
} Page;

Page* backStack = NULL;
Page* forwardStack = NULL;
Page* current = NULL;

Page* createPage(char* url) {
    Page* page = (Page*)malloc(sizeof(Page));
    strcpy(page->url, url);
    time_t now = time(NULL);
    strftime(page->timestamp, sizeof(page->timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    page->next = NULL;
    return page;
}

void push(Page** stack, Page* page) {
    page->next = *stack;
    *stack = page;
}

Page* pop(Page** stack) {
    if (!*stack) return NULL;
    Page* temp = *stack;
    *stack = (*stack)->next;
    return temp;
}

void visit(char* url) {
    if (current) push(&backStack, current);
    current = createPage(url);
    while (forwardStack) free(pop(&forwardStack));
    printf("Da truy cap %s\n", url);
}

void goBack() {
    if (!backStack) {
        printf("Khong the quay lai\n");
        return;
    }
    push(&forwardStack, current);
    current = pop(&backStack);
    printf("Da quay lai %s\n", current->url);
}

void goForward() {
    if (!forwardStack) {
        printf("Khong the tien toi\n");
        return;
    }
    push(&backStack, current);
    current = pop(&forwardStack);
    printf("Da tien toi %s\n", current->url);
}

void printCurrent() {
    if (current)
        printf("Trang hien tai: %s | Thoi gian: %s\n", current->url, current->timestamp);
    else
        printf("Chua truy cap trang nao\n");
}

int main() {
    char cmd[100], url[100];
    int ch;
    while (1) {
        printf("\nWEB HISTORY\n");
        printf("1. VISIT\n");
        printf("2. BACKWARD\n");
        printf("3. FORWARD\n");
        printf("4. CURRENT\n");
        printf("5. THOAT\n");
        printf("Nhap lua chon: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Nhap url: ");
                scanf("%s", url);
                visit(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                printCurrent();
                break;
            case 5:
                printf("Tam biet\n");
                return 0;
            default:
                printf("Khong hop le\n");
        }
    }
}
