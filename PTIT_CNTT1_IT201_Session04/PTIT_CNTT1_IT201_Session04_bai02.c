//
// Created by FPT on 6/25/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("nhap so luong ptu: ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("nhap ptu\n");
    for(int i=0;i<n;i++) {
        printf("arr[%d]",i),
        scanf("%d",&arr[i]);
    }
    int number;
    printf("nhap gtri can tim: ");
    scanf("%d",&number);
    for(int i=0;i<=n;i++) {
        if(arr[i]==number) {
            printf("%d ",arr[i]);
        }
    }
free(arr);
    return 0;
}