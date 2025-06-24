//
// Created by FPT on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>


int sumRow(int **arr, int cols,int k) {
    int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += arr[k][j];
        }
        return sum;
}
void inputArray(int **arr, int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
}

int main() {
    int rows,cols,k;
    while (1) {
        scanf("%d",&rows);
        if (rows <= 0||rows>=1000) {
            scanf("%d",&cols);
            printf("so hang ko hop le\n");
            return 0;
        }
        scanf("%d",&cols);
        if (cols <= 0||cols>=1000) {
            printf("so cot ko hop le\n");
            return 0;
        }
        int **arr=(int **)malloc(rows*sizeof(int *));
        if (arr==NULL) {
            printf("loi\n");
            return 1;
        }
        for (int i = 0; i < rows; i++) {
            arr[i]=(int *)malloc(cols*sizeof(int));
            if (arr[i]==NULL) {
                printf("loi\n");
                return 1;
            }
        }
        inputArray(arr,rows,cols);
        scanf("%d",&k);
        if (k<0||k>rows) {
            printf("hang can tinh ko ton tai");
        }else {
            int sum = sumRow(arr,cols,k);
            printf("sum = %d\n",sum);
        }
        for (int j = 0; j < rows; j++) {
            free(arr[j]);
        }
        free(arr);
    if (rows == 0) break;

    }








    return 0;
}