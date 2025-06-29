//
// Created by FPT on 6/27/2025.
//
#include <stdio.h>
#include <stdlib.h>
void search(int arr[],int n,int index,int* max,int *min) {
    if (index >=n) return ;

        if (arr[index] > *max) {
           *max = arr[index];
        }
    if (arr[index] < *min) {
            *min = arr[index];
        }

    search(arr,n,index + 1,max,min);
}



int main() {
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    if (n<1) {
        printf("input ko hop le: \n");
    }
    int arr[n];
    printf("nhap arr: ");
    for (int i=0; i<n; i++) {
        printf("nhap arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    search(arr,n,0,&max,&min);
    printf("max:%d\n",max);
    printf("min:%d",min);







    return 0;
}
