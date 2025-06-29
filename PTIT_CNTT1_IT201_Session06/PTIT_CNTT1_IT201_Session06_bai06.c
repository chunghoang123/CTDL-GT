//
// Created by FPT on 6/27/2025.
//
#include <stdatomic.h>
#include <stdio.h>
int demBac(int n) {
    if (n <= 0) return 1;
    if (n == 1) return 1;
        return demBac(n-1) + demBac(n-2);
    }


int main() {
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    int count = demBac(n);
    printf("nhap count: %d\n",count);

    return 0;
}