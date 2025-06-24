#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("moi nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n<0) {
        printf("so luong ko dc am: ");
    }else if (n==0) {
        printf("so luong phai lon hon 0 \n");
        return 1;
    }
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr==NULL) {
        return 1;
    }

    printf("nhap cac pt: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 1;
    for (int i = 0; i < n; i++) {
        printf("so thu %d = %d \n",count,arr[i]);
        count ++;
    }

    free(arr);

    return 0;
}