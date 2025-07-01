//
// Created by FPT on 7/1/2025.
//
#include <stdio.h>

int search(int  arr[], int n, int sear) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == sear)
            return i+1;
    }
    return -1;
}


int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    int arr[n];
    printf("nhap arr: ");
    for (int i = 0; i < n; i++) {
        printf("nhap arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
    int sear;
    printf("nhap sear: ");
    scanf("%d", &sear);

    int result = search(arr, n, sear);
    if (result != -1) {
        printf("vi tri thu %d\n", result);
    }else {
        printf("ko ton tai");
    }






    return 0;
}
