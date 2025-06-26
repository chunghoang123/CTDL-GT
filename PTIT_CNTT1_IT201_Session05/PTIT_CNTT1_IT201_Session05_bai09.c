//
// Created by FPT on 6/26/2025.
//
#include<stdio.h>;

int factorial(int n) {

    if (n==0) return 1;
    return n*factorial(n-1);
}
int combination(int n, int k) {
    return factorial(n)/(factorial(k)*factorial(n-k));
}



int main() {
    int row,col;
    scanf("%d", &row);
    scanf("%d", &col);


    int result = combination(row + col -2, row - 1);
    printf("%d", result);
    return 0;
}




