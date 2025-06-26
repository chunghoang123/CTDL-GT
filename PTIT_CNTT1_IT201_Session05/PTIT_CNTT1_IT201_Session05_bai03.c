//
// Created by FPT on 6/26/2025.
//
#include <stdio.h>

int recursiveN(int n,int i,int recursive) {
    if (i>n) {
        return recursive;
    }
    return recursiveN(n,i+1,recursive*i);

}


int main() {
    int n;
    scanf("%d",&n);
    if (n<=0) {
        printf("ko hop le");
        return 0;
    }
    int result = recursiveN(n,1,1);
    printf("%d",result);








    return 0;
}
