#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Order {
    int id;
    char customer[100];
    int status;
    char total[20];
} Order;

typedef struct OrderNode {
    Order order;
    struct OrderNode *prev, *next;
} OrderNode;

typedef struct HistoryNode {
    Order order;
    struct HistoryNode *next;
} HistoryNode;

OrderNode *head = NULL, *tail = NULL;
HistoryNode *historyHead = NULL;
int nextId = 1;

OrderNode* createOrderNode(Order order) {
    OrderNode* node = (OrderNode*)malloc(sizeof(OrderNode));
    node->order = order;
    node->next = node->prev = NULL;
    return node;
}

void addOrder() {
    Order order;
    order.id = nextId++;
    getchar();
    printf("Ten khach hang: ");
    fgets(order.customer, 100, stdin);
    order.customer[strcspn(order.customer, "\n")] = 0;
    printf("Tong tien: ");
    fgets(order.total, 20, stdin);
    order.total[strcspn(order.total, "\n")] = 0;
    order.status = 0;
    OrderNode* node = createOrderNode(order);
    if (!head) head = tail = node;
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    printf("Them thanh cong.\n");
}

void displayOrders() {
    printf("--- Don hang chua giao ---\n");
    OrderNode* t = head;
    while (t) {
        printf("ID:%d | KH:%s | Tong:%s | Trang thai:%s\n", t->order.id, t->order.customer, t->order.total, t->order.status == 0 ? "Chua giao" : "Da giao");
        t = t->next;
    }
    printf("--- Lich su da giao ---\n");
    HistoryNode* h = historyHead;
    while (h) {
        printf("ID:%d | KH:%s | Tong:%s | Trang thai:Da giao\n", h->order.id, h->order.customer, h->order.total);
        h = h->next;
    }
}

void deleteOrder(int id) {
    OrderNode* t = head;
    while (t) {
        if (t->order.id == id) {
            if (t->prev) t->prev->next = t->next;
            else head = t->next;
            if (t->next) t->next->prev = t->prev;
            else tail = t->prev;
            free(t);
            printf("Da xoa ID %d\n", id);
            return;
        }
        t = t->next;
    }
    printf("Khong tim thay ID %d\n", id);
}

void updateOrder(int id) {
    OrderNode* t = head;
    while (t) {
        if (t->order.id == id) {
            getchar();
            printf("Ten moi: ");
            fgets(t->order.customer, 100, stdin);
            t->order.customer[strcspn(t->order.customer, "\n")] = 0;
            printf("Tong tien moi: ");
            fgets(t->order.total, 20, stdin);
            t->order.total[strcspn(t->order.total, "\n")] = 0;
            printf("Cap nhat thanh cong\n");
            return;
        }
        t = t->next;
    }
    printf("Khong tim thay ID %d\n", id);
}

void markDelivered(int id) {
    OrderNode* t = head;
    while (t) {
        if (t->order.id == id && t->order.status == 0) {
            t->order.status = 1;
            HistoryNode* h = (HistoryNode*)malloc(sizeof(HistoryNode));
            h->order = t->order;
            h->next = historyHead;
            historyHead = h;
            if (t->prev) t->prev->next = t->next;
            else head = t->next;
            if (t->next) t->next->prev = t->prev;
            else tail = t->prev;
            free(t);
            printf("Da giao don ID %d\n", id);
            return;
        }
        t = t->next;
    }
    printf("Khong tim thay hoac da giao ID %d\n", id);
}

int toInt(char* s) {
    return atoi(s);
}

void sortOrders() {
    OrderNode* i = head;
    while (i) {
        OrderNode* j = i->next;
        while (j) {
            if (toInt(i->order.total) > toInt(j->order.total)) {
                Order tmp = i->order;
                i->order = j->order;
                j->order = tmp;
            }
            j = j->next;
        }
        i = i->next;
    }
    printf("Sap xep thanh cong\n");
}

void searchOrder(char* name) {
    int found = 0;
    OrderNode* t = head;
    while (t) {
        if (strstr(t->order.customer, name)) {
            printf("CHUA GIAO - ID:%d | KH:%s | Tong:%s\n", t->order.id, t->order.customer, t->order.total);
            found = 1;
        }
        t = t->next;
    }
    HistoryNode* h = historyHead;
    while (h) {
        if (strstr(h->order.customer, name)) {
            printf("DA GIAO   - ID:%d | KH:%s | Tong:%s\n", h->order.id, h->order.customer, h->order.total);
            found = 1;
        }
        h = h->next;
    }
    if (!found) printf("Khong tim thay\n");
}

int main() {
    int ch, id;
    char name[100];
    while (1) {
        printf("\nORDER MANAGER\n");
        printf("1. Them don hang\n");
        printf("2. Hien thi\n");
        printf("3. Xoa\n");
        printf("4. Cap nhat\n");
        printf("5. Giao hang\n");
        printf("6. Sap xep\n");
        printf("7. Tim kiem\n");
        printf("8. Thoat\n");
        printf("Chon: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addOrder(); break;
            case 2: displayOrders(); break;
            case 3: printf("ID: "); scanf("%d", &id); deleteOrder(id); break;
            case 4: printf("ID: "); scanf("%d", &id); updateOrder(id); break;
            case 5: printf("ID: "); scanf("%d", &id); markDelivered(id); break;
            case 6: sortOrders(); break;
            case 7: getchar(); printf("Ten khach: "); fgets(name, 100, stdin); name[strcspn(name, "\n")] = 0; searchOrder(name); break;
            case 8: return 0;
            default: printf("Khong hop le\n");
        }
    }
}
