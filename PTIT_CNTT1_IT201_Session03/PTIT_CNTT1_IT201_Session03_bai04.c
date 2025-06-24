//
// Created by FPT on 6/20/2025.
//
#include <stdio.h>
#include <stdio.h>


int main () {
    int rows ;
    int cols ;
    printf("moi nhap so cot: ");
    scanf("%d", &rows);
    printf("moi nhap so hang: ");
    scanf("%d", &cols);
    if (rows <1) {
        printf("so cot ko hop le\n");
    }else if (cols <1) {
        printf("so hang ko hop le\n");
    }else if (cols == 0 && rows == 0) {
        printf("so cot & hang ko hop le\n");
        return 0;
    }
    int arr[rows][cols];
    printf("moi nhap cac ptu: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int max = arr[0][0];
    int min = arr[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }

    printf("max = %d \n",max);
    printf("min = %d ",min);





    return 0;
}