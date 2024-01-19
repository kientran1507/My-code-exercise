#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20
int step;

// Node structure for the binary search tree
typedef struct TreeNode {
    int data;
    char code[MAX_LEN];
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to insert a new node into the binary search tree
TreeNode* insertBST(TreeNode* root, int data, const char* code) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = data;
        strncpy(newNode->code, code, MAX_LEN - 1);
        newNode->code[MAX_LEN - 1] = '\0';
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (data < root->data) {
        root->left = insertBST(root->left, data, code);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data, code);
    }

    return root;
}

// Function to count the steps for a given code in the binary search tree
int countStepsBST(TreeNode* root, int data) {
    if (root == NULL) {
        return step; // Code not found, return the total steps
    }

    if (root->data == data) {
        step++;
        return step;
    } else if (data < root->data) {
        step++;
        return countStepsBST(root->left, data);
    } else {
        step++;
        return countStepsBST(root->right, data);
    }
}

// Function to perform in-order traversal and print the data with leading zeros
void inOrderPrintData(TreeNode* root, int* first) {
    if (root != NULL) {
        inOrderPrintData(root->left, first);
        if (*first) {
            *first = 0;
        } else {
            printf(" ");
        }
        printf("%02d", root->data);
        inOrderPrintData(root->right, first);
    }
}

// Function to free the memory allocated for the binary search tree
void freeBST(TreeNode* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main() {
    TreeNode* root = NULL;

    // Process the input
    char command[MAX_LEN];
    int data;
    char code[MAX_LEN];

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "insert") == 0) {
            scanf("%d %s", &data, code);
            root = insertBST(root, data, code);
        } else if (strcmp(command, "countStep") == 0) {
            scanf("%d", &data);
            int result = countStepsBST(root, data);
            printf("%d\n", result);
        } else if (strcmp(command, "inOrder") == 0) {
            int first = 1;
            inOrderPrintData(root, &first);
            printf("!\n");
        } else if (strcmp(command, "#") == 0) {
            break;
        }
    }

    // Free allocated memory
    freeBST(root);

    return 0;
}
