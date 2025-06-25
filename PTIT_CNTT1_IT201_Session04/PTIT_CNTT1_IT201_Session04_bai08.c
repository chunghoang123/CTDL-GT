//
// Created by FPT on 6/25/2025.
//
#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    printf("nhap so luong ptu");
    scanf("%d", &n);


    int arr[n];

    printf("nhap ptu: \n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int number ;
    int found = 0;
    printf("moi nhap pt can tim: ");
    scanf("%d", &number);
    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            printf("vi tri %d \n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("ptu ko cs trong mang\n");
    }




    return 0;
}