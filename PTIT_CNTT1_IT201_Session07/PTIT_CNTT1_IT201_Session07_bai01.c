#include <stdio.h>

void bubbleSort(int arr[], int n) {
    if (n==0) return;
    bubbleSort(arr, n-1);
    for (int i=0; i<n-1; i++) {
        if (arr[i]>arr[i+1]) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    bubbleSort(arr, n-1);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("mang  dc sap xep:\n");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");





    return 0;
}
