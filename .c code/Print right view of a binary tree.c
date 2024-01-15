#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (root->left == NULL) {
        root->left = insert(root->left, value);
    } else {
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

struct Node* del(struct Node* root, int value) {
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

// Function to print nodes visible from the right side
void printRightViewHelper(struct Node* root, int level, int* maxLevel) {
    if (root == NULL) {
        return;
    }

    // Check if the current level is greater than the maximum level seen so far
    if (level > *maxLevel) {
        printf("%d\n", root->data);
        *maxLevel = level;
    }

    // Recursively traverse the right subtree first, then the left subtree
    printRightViewHelper(root->right, level + 1, maxLevel);
    printRightViewHelper(root->left, level + 1, maxLevel);
}

// Wrapper function to initialize the maximum level
void printRightView(struct Node* root) {
    int maxLevel = 0;
    printRightViewHelper(root, 1, &maxLevel);
}

int main() {
    struct Node* root = NULL;
    int value;
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) {
            printRightView(root);
            if (root == NULL) printf("NULL");
            break;
        } else if (strcmp(cmd, "insert") == 0) {
            scanf(" %d", &value);
            root = insert(root, value);
        } else if (strcmp(cmd, "del") == 0) {
            scanf(" %d", &value);
            root = del(root, value);
        }
    }
    return 0;
}
