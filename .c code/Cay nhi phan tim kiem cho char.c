#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value == root->data) {
        return root;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}


struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* del(struct Node* root, char value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = del(root->left, value);
    else if (value > root->data)
        root->right = del(root->right, value);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}

void printTree(struct Node* r) {
    if (r == NULL) {
        //printf("NULL");
        return;
    }
    printTree(r->left);
    printTree(r->right);
    printf("%c ", r->data);
}

int main() {
    struct Node* root = NULL;
    char value;
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) {
            printTree(root);
            if (root == NULL) printf("NULL");
            break;
        } else if (strcmp(cmd, "insert") == 0) {
            scanf(" %c", &value);
            root = insert(root, value);
        } else if (strcmp(cmd, "del") == 0) {
            scanf(" %c", &value);
            root = del(root, value);
        }
    }
    return 0;
}
