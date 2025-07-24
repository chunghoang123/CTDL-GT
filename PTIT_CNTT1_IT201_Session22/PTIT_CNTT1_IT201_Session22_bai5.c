#include <stdio.h>

int main() {
    int n, v;
    int u, w;
    int adjMatrix[100][100] = {0};
    int k, count = 0;

    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        scanf("%d %d", &u, &w);
        adjMatrix[u][w] = 1;
        adjMatrix[w][u] = 1;
    }

    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        if (adjMatrix[k][i] == 1) {
            count++;
        }
    }

    printf("So dinh ke voi %d la: %d\n", k, count);

    return 0;
}
