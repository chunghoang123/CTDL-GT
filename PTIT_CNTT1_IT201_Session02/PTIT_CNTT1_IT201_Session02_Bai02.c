#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,x;
    printf("moi nhap so luong phan tu (0<n<=100)\n");
    scanf("%d",&n);

    if (n<=0|| n>100) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("khong du bo nho\n");
        return 1;
    }
    printf("moi nhap phan tu cua mang\n");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("nhap so can dem\n");
    scanf("%d",&x);
    int count=0;
    for (int i = 0; i < n; i++) {
        if (arr[i]==x) {
            count++;
        }
    }
    printf("so lan xuat hien: %d\n",count);

    free(arr);
    return 0;
}
