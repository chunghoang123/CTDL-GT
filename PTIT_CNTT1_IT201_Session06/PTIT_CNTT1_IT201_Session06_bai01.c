#include <stdio.h>
void nhiPhan(int n) {
    if (n==0) {
        return 1;
    }
    printf("%d",n%2);
    nhiPhan(n/2);
}
int main() {
int n;
printf("nhap n: ");
    scanf("%d", &n);
    nhiPhan(n);

return 0;
}