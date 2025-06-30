#include <stdio.h>
#include <string.h>

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}


void sort_string(char *s, char *result) {

    if (s == NULL || strlen(s) == 0) {
        strcpy(result, "loi");
        return;
    }

    char temp[100];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            temp[j] = to_lower(s[i]);
            j++;
        }
    }
    temp[j] = '\0';
    if (j == 0) {
        strcpy(result, "loi");
        return;
    }

    int len = strlen(temp);
    for (int i = 0; i < len - 1; i++) {
        for (int k = 0; k < len - i - 1; k++) {
            if (temp[k] > temp[k + 1]) {
                char t = temp[k];
                temp[k] = temp[k + 1];
                temp[k + 1] = t;
            }
        }
    }

    strcpy(result, temp);
}

int main() {
    char str1[] = "algorithm";
    char result1[100];
    printf("INPUT: %s\n", str1);
    sort_string(str1, result1);
    printf("OUTPUT: %s\n", result1);

    char str2[] = "";
    char result2[100];
    printf("\nINPUT: %s\n", str2);
    sort_string(str2, result2);
    printf("OUTPUT: %s\n", result2);

    return 0;
}