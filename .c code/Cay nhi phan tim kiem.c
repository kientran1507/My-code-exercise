#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value >= root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int isValid(struct Node* root, int minValue, int maxValue) {
    if (root == NULL) {
        return 1;
    }

    if (root->data <= minValue || root->data >= maxValue) {
        return 0;
    }

    return isValid(root->left, minValue, root->data) && isValid(root->right, root->data, maxValue);
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    if (isValid(root, INT_MIN, INT_MAX)) {
        printf("Cay la mot cay nhi phan tim kiem hop le.\n");

        printf("Nhap gia tri can tim kiem: ");
        scanf("%d", &value);

        struct Node* result = search(root, value);
        if (result != NULL) {
            printf("Gia tri %d co ton tai trong cay.\n", value);
        } else {
            printf("Gia tri %d khong ton tai trong cay.\n", value);
        }
    } else {
        printf("Cay khong phai la cay nhi phan tim kiem hop le.\n");
    }

    return 0;
}
