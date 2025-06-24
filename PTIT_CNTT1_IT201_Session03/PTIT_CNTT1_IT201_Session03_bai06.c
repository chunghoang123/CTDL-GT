
#include <stdio.h>
#include <stdlib.h>



void inputArray(int *arr,int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
}
void printArray(int *arr,int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
        if (i<n-1) printf(", ");
    }
    printf("\n");
}

int main() {
    int n ,m;
    while (1) {
        scanf("%d",&n);
        if (n<0) {
            printf("so luong pt ko dc am\n");
        }else if (n==0) {
            printf("so luong pt phai lon hon 0""\n");
            break;
        }
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Lỗi cấp phát bộ nhớ!\n");
            return 1;
        }

        inputArray(arr,n);
        scanf("%d",&m);
        arr = (int *)realloc(arr,n * sizeof(int));
        if (arr == NULL && (n+m)>0) {
            printf("loi");
            return 1;
        }
        if (m>0) {
            inputArray(arr+n,m);
        }
        printArray(arr,n);
        free(arr);

    }



    return 0;
}
