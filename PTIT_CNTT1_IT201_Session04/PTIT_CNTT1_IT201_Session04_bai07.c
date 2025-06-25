//
// Created by FPT on 6/25/2025.
//
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
void findSymmetricPairs(int arr[],int n) {
    int found = 0;
    for (int i = 0; i < n/2; i++) {

        if (arr[i] == arr[n-1-i]) {
            printf("cap doi xung:(%d,%d)\n",arr[i],arr[n-1-i]);
            found = 1;
        }
    }
    if (!found) {
        printf("ko co cap doi xung\n");
    }



}

int main() {
    int n;
    printf("nhap so luong pt");
    scanf("%d", &n);
    int arr[n];

    printf("nhap cac ptu");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    findSymmetricPairs(arr, n);





    return 0;
}