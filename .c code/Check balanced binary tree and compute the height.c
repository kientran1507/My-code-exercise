#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int id;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* MakeRoot(struct Node* root, int value) {
    root = createNode(value);
    return root;
}

// Function to find a node with a specific id in the tree using iterative level-order traversal
struct Node* findNode(struct Node* root, int id) {
    if (root == NULL) {
        return NULL;
    }

    struct Node* current;
    struct Node* queue[50000];  // Assuming the maximum number of nodes is 50000
    size_t front = 0, rear = 0; // Use size_t for indices

    queue[rear++] = root;

    while (front < rear) {
        current = queue[front++];

        if (current->id == id) {
            return current;
        }

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    return NULL;
}

struct Node* AddLeft(struct Node* root, int u, int v) {
    struct Node* parent = findNode(root, v);

    if (parent == NULL) {
        // The parent node doesn't exist, create it
        root = createNode(v);
        parent = root;
    }

    parent->left = createNode(u);

    return root;
}

struct Node* AddRight(struct Node* root, int u, int v) {
    struct Node* parent = findNode(root, v);

    if (parent == NULL) {
        // The parent node doesn't exist, create it
        root = createNode(v);
        parent = root;
    }

    parent->right = createNode(u);

    return root;
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
            root = MakeRoot(root, u);
        } else if (strcmp(command, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            root = AddLeft(root, u, v);
        } else if (strcmp(command, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            root = AddRight(root, u, v);
        }
    }

    int isBalanced = 1;
    int h = heightAndBalance(root, &isBalanced);

    printf("%d %d\n", isBalanced, h);

    return 0;
}
