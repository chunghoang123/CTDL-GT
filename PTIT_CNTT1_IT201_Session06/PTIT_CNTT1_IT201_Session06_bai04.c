//
// Created by FPT on 6/27/2025.
//
#include <stdio.h>
#include <stdlib.h>

void thap(int n, char source, char auxiliary, char destination ) {
    if (n>0) {
        thap(n-1, source, destination, auxiliary);

        printf("dia %d di chuyen tu %c sang %c\n",n, source,destination);

        thap(n-1, auxiliary, source, destination);
    }

}
int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("so luong ko hop le");
    }else {
        thap(n, 'A', 'B', 'C');
    }




    return 0;
}

