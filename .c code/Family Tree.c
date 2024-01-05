#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char child[20];
    char parent[20];
} Relation;

Relation relations[MAX];
int count = 0;

int findDescendants(char name[]) {
    int i, descendants = 0;
    for (i = 0; i < count; i++) {
        if (strcmp(relations[i].parent, name) == 0) {
            descendants += 1 + findDescendants(relations[i].child);
        }
    }
    return descendants;
}

int findGeneration(char name[]) {
    int i, maxGen = 0;
    for (i = 0; i < count; i++) {
        if (strcmp(relations[i].parent, name) == 0) {
            int currentGen = 1 + findGeneration(relations[i].child);
            if (currentGen > maxGen) {
                maxGen = currentGen;
            }
        }
    }
    return maxGen;
}

void printTree() {
    printf("Child\tParent\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", relations[i].child, relations[i].parent);
    }
}

int main() {
    char cmd[20], param[20];
    char stop[10];

    // Reading child-parent relations
    while (1) {
        if (scanf("%s", relations[count].child) != 1) {
            break;  // End of input or ***
        }
        
        if (strcmp(relations[count].child, "***") == 0) {
            break;  // Stop reading when *** is encountered
        }

        scanf("%s", relations[count].parent);
        count++;
        if (count >= MAX) {
            break;
        }
    }

    // Print the tree for debugging
    printTree();

    // Processing queries
    while (1) {
        // Read the command
        if (scanf("%s", cmd) != 1) {
            break; // End of input
        }

        if (strcmp(cmd, "***") == 0) {
            break; // Terminate the loop upon encountering ***
        } else if (strcmp(cmd, "descendants") == 0) {
            scanf("%s", param);
            printf("%d\n", findDescendants(param));
        } else if (strcmp(cmd, "generation") == 0) {
            scanf("%s", param);
            printf("%d\n", findGeneration(param));
        }
    }

    return 0;
}
