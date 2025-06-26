//
// Created by FPT on 6/26/2025.
//
#include <stdio.h>
void print1ToNRecursion(int n,int i ){
    if (i>n) {
        return;
    }
    printf("%d",i);

    print1ToNRecursion(n,i+1);
}
int main() {
    int n;
    scanf("%d ",&n);

    print1ToNRecursion(n,1);






    return 0;
}