//
// Created by FPT on 7/1/2025.
//

#include <stdio.h>
void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n-1; i++) {
        int counter = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                counter=1;
            }
        }
        if (counter == 0) {
            return;
        }
    }
}


int main() {
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    int arr[n];
    printf("nhap arr: ");
    for (int i = 0; i < n; i++) {
        printf("nhap arr[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");




    return 0;
}
