//
// Created by FPT on 6/26/2025.
//
#include <stdio.h>
int sumFirstToSecond(int firstNum,int secondNum, int sum) {
   if (firstNum > secondNum) {
       return sum;
   }
    return sumFirstToSecond(firstNum+1,secondNum,sum+firstNum);
}


int main() {
    int firstNum;
    scanf("%d",&firstNum);
    int secondNum;
    scanf("%d",&secondNum);
    if(firstNum<1||secondNum<1) {
        printf("Error");
        return 0;
    }
    int result = sumFirstToSecond(firstNum,secondNum,0);
    printf("%d",result);

}