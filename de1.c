//
// Created by FPT on 7/18/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  Task {
    int id;
    char title[50];
    int prioriry;
    char deadline[50];
}Task;



typedef struct Node {
    Task data;
    struct Node *next;
}Node;
typedef struct DNode {
    Task data;
    struct DNode *next;
    struct DNode *prev;
}DNode;
Node *head = NULL;
DNode *completed = NULL;

Node *creareNode(Task t) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = t;
    newNode->next = NULL;
    return newNode;
}
DNode *creareDNode(Task t) {
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = t;
    newNode->next = NULL;
    return newNode;
}


void addTask() {
    Task t;
    printf("nhap id: ");
    scanf("%d", &t.id);
    getchar();
    printf("nhap title: ");
    fgets(t.title, 50, stdin);
    t.title[strlen(t.title) - 1] = '\0';
    printf("nhap priori(0/1): ");
    scanf("%d", &t.prioriry);
    getchar();
    printf("nhap deadline: ");
    fgets(t.deadline, 50, stdin);
    t.deadline[strlen(t.deadline) - 1] = '\0';

    Node* newNode = creareNode(t);
    newNode->next = head;
    head = newNode;
    printf("them thanh cong\n");
}

void displayTask() {
    Node *temp = head;
    if (!temp) {
        printf("danh sach trong: ");
        return;
    }
    printf("danh sach hoat dong trong ngay\n");
    while (temp) {
        printf("ID: %d - Titles: %s - Priori: %d - Deadline: %s \n",temp->data.id, temp->data.title, temp->data.prioriry, temp->data.deadline);
        temp = temp->next;
    }
}

void deleteTask() {
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);
    Node*temp = head;
    Node*prev = NULL;
    while (temp&&temp->data.id != id) {
        prev = temp;
        temp = temp->next;

    }
    if (!temp) {
        printf("ID khong ton tai\n ");
        return;
    }
    if (!prev) {
        head = temp->next;
    }else {
        prev->next = temp->next;
    }
    free(temp);
    printf("xoa thanh cong\n");
}

void updateTask() {
    int id;
    printf("Nhap ID can cap nhat: ");
    scanf("%d", &id);
    Node*temp = head;
    while (temp&&temp->data.id != id) {
        temp = temp->next;
    }
    if (!temp) {
        printf("ID khong ton tai\n ");
        return;
    }
    getchar();
    printf("Nhap title: ");
    fgets(temp->data.title, sizeof(temp->data.title), stdin);
    temp->data.title[strlen(temp->data.title)-1] = '\0';
    printf("Nhap priorriry: ");
    scanf("%d", &temp->data.prioriry);
    printf("Nhap deadline: ");
    fgets(temp->data.deadline, sizeof(temp->data.deadline), stdin);
    temp->data.deadline[strlen(temp->data.deadline)-1] = '\0';
}

void completedTask() {
    int id;
    printf("Nhap ID can danh hoan thanh: ");
    scanf("%d", &id);
    Node*temp = head;
    Node *prev = NULL;
    while (temp && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("ID khong ton tai\n ");
        return;
    }
    if (!prev) {
        head = temp->next;

    }
    else {
        prev->next = temp->next;

    }
    DNode* newNode = creareNode(temp->data);
    newNode->next = completed;
    if (completed) {
        completed->prev = newNode;
        completed = newNode;

    }
    free(temp);
    printf("danh hoan thanh thanh cong\n");


}
int countNode(Node *head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;

}


void sortTask() {
    int n = countNode(head);
    if (n < 2) {
        printf("dsanh da dc sap xep\n");
        return;
    }
    for (int i = 1; i < n; i++) {
        Node* temp = head;
        Node* q = head->next;
        for (int j = 0; j < n-i-1; j++) {
            if (temp->data.prioriry> q->data.prioriry) {
                Task current = temp->data;
                temp->data = q->data;
                q->data = current;
            }
            temp = temp->next;
            q = q->next;
        }
    }

}
void searchCourse() {
    char keyWord[100];
    getchar();
    printf("nhap ten can tim");
    scanf("%s", keyWord);
    fgets(keyWord, 100, stdin);
    keyWord[strcspn(keyWord, "\n")] = 0;
    Node*temp = head;
    int found = 0;
    while (temp) {
        if (strstr(keyWord, temp->data.title)) {
            printf("ID: %d - Titles: %s - Priori: %d - Deadline: %s \n",temp->data.id, temp->data.title, temp->data.prioriry, temp->data.deadline);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("ko tim thay khoa hc\n");
    }
}

void freeAll() {
    Node*temp ;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    DNode* q;
    while (completed) {
        q = completed;
        completed = completed->next;
        free(q);

    }
}


int main() {
    int choice;


    Task t1 = {01,"chay",1,"10:30"};
    Task t2 = {02,"nhay",5,"1:30"};
    Task t3 = {03,"boi",2,"5:00"};

    Node* n1 = creareNode(t1);
    Node* n2 = creareNode(t2);
    Node* n3 = creareNode(t3);

    n3->next = head;
    head = n3;
    n2->next = head;
    head = n2;
    n1->next = head;
    head = n1;

    do {
        printf("========================= MENU =========================\n");
        printf("1. Them moi nhiem vu\n");
        printf("2. Hien thi danh sach nhiem vu\n");
        printf("3. xoa nhiem vu\n");
        printf("4. Cap nhat nhiem vu\n");
        printf("5. Danh dau nhiem vu hoan thanh\n");
        printf("6. Sap xep nhiem vu\n");
        printf("7. tim kiem niem vu\n");
        printf("8. thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                updateTask();
                break;
            case 5:
                completedTask();
                break;
            case 6:
                sortTask();
                break;
            case 7:
                searchCourse();
                break;
            case 8:
                printf("ket thuc truong trinh\n");
                break;
            default:
                printf("nhap sai moi nhap lai\n");
                break;
        }

    }while(choice != 8);
    return 0;
}