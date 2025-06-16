#include <stdio.h>
#include <stdlib.h>
//bài 1
int main(){
    int n;
for (int i = 0;i< n;i++) {
    printf("Hello\n");
}
    return 0;
}
//Độ phức tạp O(n)

//bài 2

void printDouble(int n) {
    int i = 1;
    while (i <= n) {
        printf("%d\n ", i);
        i *= 2;
    }
}
//độ phức tạp O(log n)

// bài 3

int* mallocArray(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}

//độ phức tạp O(n)

// bài 4
// cách 1
 long long sumLoop(int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i;
    }
    return sum;
}
 long long sumFormula(int n) {
    return (long long)n * (n+1) / 2;
}
// độ phức tạp O(n)

// cách 2
int main() {
    int n;
    printf("moi nhap so n");
    scanf("%d", &n);

    long long result = sumLoop(n);
    long long result2 = sumFormula(n);
    printf("%lld\n", result);
    printf("%lld\n", result2);
    return 0;
}
// độ phức tạp O(1)

//bài 5
void bubbleSort(int arr[], int n) {
    int swapped;
    int temp;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}
int main () {
    int n,i;
    printf("moi nhap so n");
    scanf("%d", &n);
    int arr[n];
    printf("nhap cac ptu n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    return 0;
}
// độ phực tạp O(n)





