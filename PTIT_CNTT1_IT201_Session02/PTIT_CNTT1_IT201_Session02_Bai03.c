#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("moi nhap so luong phan tu: ");
    scanf("%d",&n);
    if (1>n>=100) {
        printf("so luong lon hon hoa be hon yeu cau");
        return 1;
    }
    int *arr=(int *)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("ko du bo nho");
        return 1;
    }
    printf("nhap cac phan tu\n");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }


    for (int i = 0; i < n/2; i++) {
        int temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    printf("mang sau khi dao nguoc: [");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
        if (i!=n-1) {
            printf(",");
        }
    }
    printf("]\n");
    free(arr);


    return 0;
}
