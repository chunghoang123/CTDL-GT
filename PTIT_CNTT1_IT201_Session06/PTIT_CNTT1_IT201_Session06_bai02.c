//
// Created by FPT on 6/27/2025.
//
#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
void printFibonacci(int n) {
    for (int i = n; i >= 1 ; i--) {
        printf("%d ", fibonacci(i));
        if (i>1) printf(", ");
    }
}

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    if (n<1) {
        printf("input ko hop le \n ");
    }else {
        printFibonacci(n);
    }
    printf("\n");
    return 0;
}