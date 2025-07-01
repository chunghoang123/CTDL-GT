//
// Created by FPT on 7/1/2025.
//

#include <stdio.h>

int bSearch(int arr[],int l,int r,int search ) {
    while (l<=r) {
        int mid = l+(r-l)/2;
        if (arr[mid] == search) {
            return mid+1;
        }
        if (arr[mid] < search) {
            l = mid+1;
        }else {
            r = mid-1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    int arr[n];
    printf("nhap arr: ");
    for(int i=0;i<n;i++) {
        printf("nhap arr[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }
    int search;
    printf("nhap search: ");
    scanf("%d",&search);
    int result = bSearch(arr,0,n-1,search);
    if (result != -1) {
        printf("vi tri thu %d ",result);
    }else {
        printf("ko ton tai");
    }



    return 0;
}
