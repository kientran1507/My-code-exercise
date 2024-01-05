#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* findNode(Node* root, int id) {
    if (root == NULL) return NULL;
    if (root->id == id) return root;
    Node* left = findNode(root->left, id);
    if (left) return left;
    return findNode(root->right, id);
}

void addLeft(Node* root, int childID, int parentID) {
    Node* parent = findNode(root, parentID);
    if (parent && !parent->left) {
        parent->left = createNode(childID);
    }
}

void addRight(Node* root, int childID, int parentID) {
    Node* parent = findNode(root, parentID);
    if (parent && !parent->right) {
        parent->right = createNode(childID);
    }
}


// Function to calculate the height of the tree and check if it is balanced
int heightAndBalance(struct Node* root, int* isBalanced) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = heightAndBalance(root->left, isBalanced);
    int rightHeight = heightAndBalance(root->right, isBalanced);

    // Check if the subtree is balanced
    if (abs(leftHeight - rightHeight) > 1) {
        *isBalanced = 0;
    }

    // Return the height of the current subtree
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int main() {
    struct Node* root = NULL;
    char command[20];
    int u, v;

    while (1) {
        scanf("%s", command);
        if (command[0] == '*') {
            break;
        }
        if (strcmp(command, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = createNode(u);
        } else if (strcmp(command, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            addLeft(root, u, v);
        } else if (strcmp(command, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            addRight(root, u, v);
        }
    }

    int isBalanced = 1;
    int h = heightAndBalance(root, &isBalanced);

    printf("%d %d\n", isBalanced, h);

    return 0;
}
