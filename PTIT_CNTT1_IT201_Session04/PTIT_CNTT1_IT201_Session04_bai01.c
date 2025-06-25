#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("nhap so luong ptu: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("nhap cac ptu:\n ");
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d:", i);
        scanf("%d", &arr[i]);
    }
    int number;
    printf("moi nhap gia tri can tim: ");
    scanf("%d", &number);
    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            printf("gia tri %d nam o vi tri thu %d",number,i);
            break;
        }else {
            printf("ko tim  thay phan tu");
            break;
        }
    }



free(arr);

    return 0;
}
