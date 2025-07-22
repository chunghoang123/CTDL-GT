#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int n) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelorder(Node *root) {
    if (root == NULL) return;

    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node *temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

int main() {
    // Tạo cây như hình yêu cầu
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("preorder:\n");
    preorder(root);
    printf("\n");

    printf("inorder:\n");
    inorder(root);
    printf("\n");

    printf("postorder:\n");
    postorder(root);
    printf("\n");

    printf("levelorder:\n");
    levelorder(root);
    printf("\n");

    return 0;
}
