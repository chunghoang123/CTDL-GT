//
// Created by FPT on 6/27/2025.
//
#include <stdio.h>
#include <stdlib.h>
int tong(int n) {
    if (n == 0) return 0;
    return (n %10) + tong(n / 10);
}
int main() {
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    if (n<1) {
        printf("input ko hop le: \n");
    }else {
       int sum = tong(n);
        printf("%d ",sum);

    }







    return 0;
}
