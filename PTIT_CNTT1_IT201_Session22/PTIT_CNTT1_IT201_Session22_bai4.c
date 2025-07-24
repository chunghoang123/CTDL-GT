#include <stdio.h>

int main() {
    int n;
    int adjMatrix[100][100];
    int count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
