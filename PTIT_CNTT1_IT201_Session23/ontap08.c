
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct Student {
    int id;
    char name[20];
    bool status;
    int avg;
} Student;

typedef struct Node {
    Student student;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct StudentList {
    Student student[MAX];
    int count;
    Node *studentHead;
} StudentList;
void initStudent(StudentList *studentList) {
    studentList->studentHead = NULL;
    studentList->count = 0;
}

void addStudent(StudentList *studentList) {
    if (studentList->count >= MAX) {
        printf("Mang day!\n");
        return;
    }

    Student newStudent;
    printf("ID: ");
    scanf("%d", &newStudent.id);
    getchar();

    for (int i = 0; i < studentList->count; i++) {
        if (studentList->student[i].id == newStudent.id) {
            printf("ID da ton tai!\n");
            return;
        }
    }

    printf("Name: ");
    fgets(newStudent.name, 20, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
    newStudent.status = true;
    printf("Average: ");
    scanf("%d", &newStudent.avg);

    studentList->student[studentList->count] = newStudent;
    studentList->count++;
    printf("Them thanh cong!\n");
}

void displayInactiveStudents(StudentList *studentList) {
    printf("\nDanh sach sinh vien khong hoat dong:\n");
    Node *current = studentList->studentHead;
    if (current == NULL) {
        printf("Khong co sinh vien khong hoat dong.\n");
        return;
    }
    printf("ID\tName\t\tStatus\tAverage\n");
    while (current != NULL) {
        printf("%d\t%-15s\t%s\t%d\n",
               current->student.id,
               current->student.name,
               "Inactive",
               current->student.avg);
        current = current->next;
    }
}
void displayStudents(StudentList *studentList) {
    printf("\nDanh sach sinh vien hoat dong:\n");
    printf("ID\tName\t\tStatus\tAverage\n");
    for (int i = 0; i < studentList->count; i++) {
        printf("%d\t%-15s\t%s\t%d\n",
               studentList->student[i].id,
               studentList->student[i].name,
               studentList->student[i].status ? "true" : "false",
               studentList->student[i].avg);
    }
    displayInactiveStudents(studentList);

}



// Delete student by ID
void deleteStudent(StudentList *studentList) {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);

    for (int i = 0; i < studentList->count; i++) {
        if (studentList->student[i].id == id) {
            for (int j = i; j < studentList->count - 1; j++) {
                studentList->student[j] = studentList->student[j + 1];
            }
            studentList->count--;
            printf("Xoa sinh vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d!\n", id);
}

void updateStudent(StudentList *studentList) {
    int id;
    printf("Nhap ID sinh vien can cap nhat: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < studentList->count; i++) {
        if (studentList->student[i].id == id) {
            printf("Nhap ten moi: ");
            fgets(studentList->student[i].name, 20, stdin);
            studentList->student[i].name[strcspn(studentList->student[i].name, "\n")] = '\0';
            printf("Nhap diem trung binh moi: ");
            scanf("%d", &studentList->student[i].avg);
            printf("Cap nhat thong tin thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d!\n", id);
}



void addToInactiveList(StudentList *studentList, Student student) {
    student.status = false;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->student = student;
    newNode->next = studentList->studentHead;
    newNode->prev = NULL;

    if (studentList->studentHead != NULL) {
        studentList->studentHead->prev = newNode;
    }
    studentList->studentHead = newNode;
}

void merge(Student arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student *L = (Student *)malloc(n1 * sizeof(Student));
    Student *R = (Student *)malloc(n2 * sizeof(Student));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].avg <= R[j].avg) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}
void changeStatus(StudentList *studentList) {
    int id;
    printf("Nhap ID sinh vien can thay doi trang thai: ");
    scanf("%d", &id);

    for (int i = 0; i < studentList->count; i++) {
        if (studentList->student[i].id == id) {
            if (studentList->student[i].status) {
                addToInactiveList(studentList, studentList->student[i]);
                for (int j = i; j < studentList->count - 1; j++) {
                    studentList->student[j] = studentList->student[j + 1];
                }
                studentList->count--;
                printf("Da chuyen sinh vien sang trang thai khong hoat dong!\n");
            } else {
                studentList->student[i].status = true;
                printf("Da chuyen sinh vien sang trang thai hoat dong!\n");
            }
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d!\n", id);
}

void mergeSort(Student arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int binarySearch(Student arr[], int size, int id) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].id == id)
            return mid;
        if (arr[mid].id < id)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void searchStudent(StudentList *studentList) {
    int id;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &id);

    Student *temp = (Student *)malloc(studentList->count * sizeof(Student));
    for (int i = 0; i < studentList->count; i++) {
        temp[i] = studentList->student[i];
    }
    mergeSort(temp, 0, studentList->count - 1);

    int index = binarySearch(temp, studentList->count, id);
    if (index != -1) {
        printf("Tim thay sinh vien:\n");
        printf("ID: %d, Name: %s, Status: %s, Average: %d\n",
               temp[index].id,
               temp[index].name,
               temp[index].status ? "Active" : "Inactive",
               temp[index].avg);
    } else {
        printf("Khong tim thay sinh vien voi ID %d!\n", id);
    }
    free(temp);

    Node *current = studentList->studentHead;
    while (current != NULL) {
        if (current->student.id == id) {
            printf("Tim thay sinh vien (khong hoat dong):\n");
            printf("ID: %d, Name: %s, Status: Inactive, Average: %d\n",
                   current->student.id,
                   current->student.name,
                   current->student.avg);
            return;
        }
        current = current->next;
    }
}

void freeInactiveList(StudentList *studentList) {
    Node *current = studentList->studentHead;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    studentList->studentHead = NULL;
}

int main() {
    StudentList studentList;
    initStudent(&studentList);
    int choice;

    do {
        printf("\n--------- STUDENT MANAGER ---------\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Cap nhat thong tin sinh vien\n");
        printf("5. Thay doi trang thai sinh vien\n");
        printf("6. Sap xep sinh vien\n");
        printf("7. Tim kiem sinh vien\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&studentList);
                break;
            case 2:
                displayStudents(&studentList);
                break;
            case 3:
                deleteStudent(&studentList);
                break;
            case 4:
                updateStudent(&studentList);
                break;
            case 5:
                changeStatus(&studentList);
                break;
            case 6:
                mergeSort(studentList.student, 0, studentList.count - 1);
                    printf("Da sap xep sinh vien theo diem trung binh!\n");
                    break;
            case 7:
                searchStudent(&studentList); break;
            case 8:
                printf("Thoat chuong trinh...\n");
                    freeInactiveList(&studentList);
                    break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}
