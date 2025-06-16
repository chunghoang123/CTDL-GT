#include <stdio.h>
#define MAX 1001
 //bài 6
int countElement(int arr[], int n , int ele){
   int count = 0;
   for(int i=0;i<n;i++){
       if(arr[i]==ele){
        count++;
        }
   }
return count;
}

int main(){
    int n,ele,i;
printf("nhap so phan tu");
scanf("%d",&n);

int arr[n];
printf("nhap cac  phan tu");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("nhap so can dem");
scanf("%d",&ele);

int result = countElement(arr,n,ele);
printf("so lan xuat hien cua: %d\n", result);
return 0;
}
// độ phức tạp O(1)

// bài 7

int hasDuplicateBruteForce(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 1; // Co trung lap
            }
        }
    }
    return 0;
}


int hasDuplicateMarking(int arr[], int n) {
    int mark[MAX] = {0};
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] < MAX) {
            if (mark[arr[i]] == 1) {
                return 1;
            }
            mark[arr[i]] = 1;
        } else {
            printf("Phan tu %d nam ngoai khoang 0-1000!\n", arr[i]);
            return -1;
        }
    }
    return 0;
}
// độ phức tạp O(n^2)

int main() {
    int n, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang (0-1000):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result1 = hasDuplicateBruteForce(arr, n);
    int result2 = hasDuplicateMarking(arr, n);

    if (result1 == 1) printf("Co trung lap (Brute Force)\n");
    else if (result1 == 0) printf("Khong co trung lap (Brute Force)\n");

    if (result2 == 1) printf("Co trung lap (Marking)\n");
    else if (result2 == 0) printf("Khong co trung lap (Marking)\n");
    else printf("Loi du lieu\n");

    return 0;
}
// độ phức tạp O(n)

// bài 8



int findMostFrequent(int arr[], int n) {
    int count[MAX] = {0};
    int maxCount = 0, mostFrequent = 0;


    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] < MAX) {
            count[arr[i]]++;
        } else {
            printf("Phan tu %d nam ngoai khoang 0-1000!\n", arr[i]);
            return -1;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostFrequent = i;
        }
    }
    return (maxCount > 0) ? mostFrequent : -1;
}
int main() {
    int n, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang (0-1000):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = findMostFrequent(arr, n);
    if (result != -1) {
        printf("Phan tu xuat hien nhieu nhat la: %d\n", result);
    } else {
        printf("Khong tim thay phan tu hop le!\n");
    }

    return 0;
}
// độ phức tạp O(n)
