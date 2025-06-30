//
// Created by FPT on 6/30/2025.
//
#include <stdio.h>

int mega(int arr[],int l,int mid,int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];
    for (int i = 0; i <n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j <n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i=0,j=0,k=l;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}
void megeSotf(int arr[],int l,int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        megeSotf(arr,l,mid);
        megeSotf(arr,mid+1,r);
        mega(arr,l,mid,r);
    }
}
void printMega(int arr[],int n){
    printf(" [");
    for (int i = 0; i <n; i++) {
        printf("%d ", arr[i]);
        if (i != n-1) {
            printf(" ,");
        }
    }
    printf("]\n");

}


int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printMega(arr,n);
    megeSotf(arr,0,n-1);


    printMega(arr,n);



    return 0;
}