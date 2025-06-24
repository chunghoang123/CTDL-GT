//
// Created by FPT on 6/20/2025.
//
#include <stdio.h>

int main() {
    int rows,cols;
    printf("moi nhap so cot: ");
    scanf("%d", &rows);
    printf("moi so hang: ");
    scanf("%d", &cols);

    if (rows == 0 && cols == 0) {
        printf("so hang va cot ko hop le");
    }else if (rows < 1) {
        printf("so cot ko hop le");
    }else if (cols < 1) {
        printf("so hang ko hop le");
    }else if (cols != rows) {
        printf("ko ton tai dg cheo chinh và phu");
    }
    int arr[rows][cols];
    int sumRows =0;
    int sumCols =0;
    printf("moi nhap cac phan tu: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("ma tran: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
       sumRows += arr[i][i];
        sumCols += arr[i][rows-1-i];


    }
printf("%d \n",sumRows);
    printf("%d \n",sumCols);






    return 0;
}