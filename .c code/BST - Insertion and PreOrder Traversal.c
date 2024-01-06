#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void preOrderTraversal(Node* root) {
    if (root) {
        printf("%d ", root->key);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    char command[100];
    int key;

    while (1) {
        fgets(command, sizeof(command), stdin);
        if (command[0] == '#') {
            break;
        }
        if (sscanf(command, "insert %d", &key) == 1) {
            root = insert(root, key);
        }
    }

    preOrderTraversal(root);
    printf("\n");

    return 0;
}
