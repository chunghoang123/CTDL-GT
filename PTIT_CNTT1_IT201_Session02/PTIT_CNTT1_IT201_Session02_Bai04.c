#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("nhap so luong ptu: \n");
    scanf("%d", &n);
    if (1>n>=100) {
        printf("nhap sai");
        return 1;
    }
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("nhap phon tinh\n");
        return 1;
    }
    printf("moi nhap cac phan tu trong mang\n");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("ptu trong mang\n");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }

    int pos,new_value;
    printf("\nmoi nhap vi tri can sua (0 - %d )\n",n);
    scanf("%d",&pos);
    if (0>=pos>=n) {
        printf("vi tri ko hop le\n");
        free(arr);
        return 1;
    }
    printf("moi nhap gia tri moi: ");
    scanf("%d",&new_value);
    arr[pos]=new_value;
    printf("mang sau khi chinh sua: [");
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