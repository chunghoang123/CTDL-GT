//
// Created by FPT on 6/26/2025.
//
#include <stdio.h>

int sumArr(int arr[],int i,int n,int sum){
    if(arr[i]>n) {
        return sum;
    }
    return  sumArr(arr,i+1,n,sum+arr[i]);
}

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d",&n);

    int arr[n];

    printf("nhap Arr: ");
    for(int i=0;i<n;i++) {
        printf("arr[%d] ",i);
        scanf("%d",&arr[i]);
    }

    int result = sumArr(arr,1,n,arr[0]);
    printf("%d ",result);



return 0;
}
