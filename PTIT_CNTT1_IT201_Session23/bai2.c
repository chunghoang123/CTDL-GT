#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Request {
    int id;
    char issue[100];
    int priority;
    struct Request *next;
} Request;

Request *highQueue = NULL;
Request *lowQueue = NULL;

Request* createRequest(int id, char issue[], int priority) {
    Request *newReq = (Request*)malloc(sizeof(Request));
    newReq->id = id;
    strcpy(newReq->issue, issue);
    newReq->priority = priority;
    newReq->next = NULL;
    return newReq;
}

void enqueue(Request **queue, Request *newReq) {
    if (*queue == NULL) {
        *queue = newReq;
    } else {
        Request *temp = *queue;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newReq;
    }
}

Request* dequeue(Request **queue) {
    if (*queue == NULL) return NULL;
    Request *temp = *queue;
    *queue = (*queue)->next;
    return temp;
}

Request* peek(Request *queue) {
    return queue;
}

void displayQueue(Request *queue) {
    while (queue != NULL) {
        printf("ID: %d | Issue: %s | Priority: %s\n", queue->id, queue->issue, (queue->priority == 1) ? "Cao" : "Thap");
        queue = queue->next;
    }
}

void sendRequest() {
    int id, priority;
    char issue[100];

    printf("Nhap ID yeu cau: ");
    scanf("%d", &id);
    getchar();

    printf("Nhap noi dung yeu cau: ");
    fgets(issue, sizeof(issue), stdin);
    issue[strcspn(issue, "\n")] = '\0';

    do {
        printf("Nhap do uu tien (1: Cao, 2: Thap): ");
        scanf("%d", &priority);
    } while (priority != 1 && priority != 2);

    Request *req = createRequest(id, issue, priority);
    if (priority == 1) {
        enqueue(&highQueue, req);
    } else {
        enqueue(&lowQueue, req);
    }

    printf("Yeu cau da duoc gui thanh cong!\n");
}

void handleRequest() {
    Request *req = NULL;
    if (highQueue != NULL) {
        req = dequeue(&highQueue);
    } else if (lowQueue != NULL) {
        req = dequeue(&lowQueue);
    }

    if (req != NULL) {
        printf("Dang xu ly yeu cau ID: %d | Noi dung: %s\n", req->id, req->issue);
        free(req);
    } else {
        printf("Khong co yeu cau nao can xu ly!\n");
    }
}

void topRequest() {
    Request *req = NULL;
    if (highQueue != NULL) {
        req = peek(highQueue);
    } else if (lowQueue != NULL) {
        req = peek(lowQueue);
    }

    if (req != NULL) {
        printf("Yeu cau gan nhat can xu ly:\n");
        printf("ID: %d | Noi dung: %s | Uu tien: %s\n", req->id, req->issue, (req->priority == 1) ? "Cao" : "Thap");
    } else {
        printf("Khong co yeu cau nao trong he thong!\n");
    }
}

void displayAll() {
    printf("=== Danh sach yeu cau uu tien cao ===\n");
    if (highQueue == NULL) printf("Khong co yeu cau nao.\n");
    displayQueue(highQueue);

    printf("=== Danh sach yeu cau uu tien thap ===\n");
    if (lowQueue == NULL) printf("Khong co yeu cau nao.\n");
    displayQueue(lowQueue);
}

int main() {
    int choice;
    do {
        printf("\n—————————— REQUEST SYSTEM ——————————\n");
        printf("1. Gui yeu cau ho tro\n");
        printf("2. Xu ly yeu cau\n");
        printf("3. Xem yeu cau gan nhat can xu ly\n");
        printf("4. Hien thi toan bo yeu cau\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sendRequest();
                break;
            case 2:
                handleRequest();
                break;
            case 3:
                topRequest();
                break;
            case 4:
                displayAll();
                break;
            case 5:
                printf("Dang thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 5);

    return 0;
}
