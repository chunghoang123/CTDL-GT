#include <stdio.h>


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int arr[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int search) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == search) {
            return mid;
        }
        if (arr[mid] < search) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;


    printf("INPUT\n");
    printf("Nhap so phan tu: ");
    scanf("%d", &n);


    if (n <= 0) {
        printf("\nOUTPUT\n");
        printf("So luong phan tu khong hop le\n");
        return 0;
    }


    int arr[n];
    printf("Nhap cac phan tu: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Mang ban dau: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n-1) printf(", ");
    }
    printf(" ]\n");


    insertionSort(arr, n);


    printf("Mang sau khi sap xep: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n-1) printf(", ");
    }
    printf(" ]\n");


    int search;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &search);

    int linearResult = linearSearch(arr, n, search);
    printf("\nKet qua tim kiem tuyen tinh: ");
    if (linearResult != -1) {
        printf("Phan tu o vi tri thu %d\n", linearResult);
    } else {
        printf("Khong ton tai phan tu\n");
    }

    // Tìm kiếm nhị phân
    int binaryResult = binarySearch(arr, 0, n-1, search);
    printf("Ket qua tim kiem nhi phan: ");
    if (binaryResult != -1) {
        printf("Phan tu o vi tri thu %d\n", binaryResult);
    } else {
        printf("Khong ton tai phan tu\n");
    }

    return 0;
}