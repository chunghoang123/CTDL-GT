//
// Created by FPT on 6/25/2025.
//
#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[20];
    int age;
};

int main() {
    struct Student student[5];;

    printf("moi nhap thong tin 5 sv : \n");
    for (int i = 0; i < 5; i++) {
        printf("moi thong tin %d sv : \n", i + 1);
        printf("nhap id: ");
        scanf("%d", &student[i].id);
        getchar();
        printf("nhap name: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strlen(student[i].name) - 1] = '\0';
        printf("nhap age: ");
        scanf("%d", &student[i].age);
    }
    int idSearch;
    printf("nhap id can tim: ");
    scanf("%d", &idSearch);

    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (student[i].id == idSearch) {
            printf("thong tin sinh vien\n");
            printf("ID: %d, Name: %s, Age: %d\n",student[i].id,student[i].name,student[i].age);
            found = 1;
            break;

        }
    }
    if (!found) {
        printf("thong tin sinh vien ko ton tai\n");
    }


    return 0;
}