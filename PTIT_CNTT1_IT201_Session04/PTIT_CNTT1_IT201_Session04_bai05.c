    //
    // Created by FPT on 6/25/2025.
    //
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int n;
        printf("nhap so luong pt: ");
        scanf("%d", &n);
        int *arr = malloc(sizeof(int) * n);
        printf("nhap cac pt");
        for (int i = 0; i < n; i++) {
            printf("nhap pt[%d]: ", i);
            scanf("%d",& arr[i]);
        }
        int number;
        printf("gtri can tim: ");
        scanf("%d", &number);
        int left = 0, right = n - 1;
       int mid = (left + (right - left) )/ 2;
        int found=0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == number) {
                printf("gtri co trong mang");
                found = 1;
                break;
            }

        }
        if (!found) {
            printf("gtri ko co trong mang");
        }
    free(arr);




        return 0;
    }
