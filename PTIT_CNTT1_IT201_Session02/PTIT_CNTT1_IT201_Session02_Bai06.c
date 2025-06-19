//
// Created by FPT on 6/19/2025.
//
#include <stdio.h>
#include <stdlib.h>
 int main() {
     int n;
     printf("moi nhap so luong ptu");
     scanf("%d",&n);
     if (1>n>=100) {
         printf("sai cu phap");
         return 1;
     }
     int *arr = (int *)malloc(n*sizeof(int));
     if (arr==NULL) {
         printf("ko du bo nho\n");
         return 1;
     }
     printf("moi nhap cac ptu: \n");
     for (int i=0;i<n;i++) {
         scanf("%d",&arr[i]);
     }
     int pos,value;
     printf("moi nhap vi tri can them (%d > vi tri >0):",n);
     scanf("%d",&pos);
     if (0>=pos>=n) {
         printf("sai vi tri\n");
         free(arr);
         return 1;
     }
     printf("moi nhap gtri muon them :\n");
     scanf("%d",&value);
     n++;
     for (int i=n-1;i>pos;i--) {
         arr[i] = arr[i-1];
     }
     arr[pos] = value;
     printf("mang khi dc them: [");
     for (int i=0;i<n;i++) {
         printf("%d ",arr[i]);
         if (i!=n-1) {
             printf(",");
         }
     }
     printf("]\n");
     free(arr);





     return 0;
 }