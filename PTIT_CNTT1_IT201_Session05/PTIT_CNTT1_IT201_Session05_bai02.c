//
// Created by FPT on 6/26/2025.
//
#include <stdio.h>
int sumN(int n, int i, int sum) {
    if (i>n) {
       return sum;
    }
    return sumN(n,i+1,sum+i);
}


int main() {
    int n;
    scanf("%d",&n);
    if (n<=0) {
        printf("ko hop le");
        return 0;
    }
    int result = sumN(n,1,0);

    printf("%d",result);





    return 0;
}



