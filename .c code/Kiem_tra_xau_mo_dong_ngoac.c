#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char c;
    struct Node* next;
} Node;

Node* top;

Node* makeNode(char x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->c = x;
    p->next = NULL;
    return p;
}

void initStack() {
    top = NULL;
}

int stackEmpty() {
    return top == NULL;
}

void push(char x) {
    Node* p = makeNode(x);
    p->next = top;
    top = p;
}

char pop() {
    if (stackEmpty()) {
        return ' ';
    }
    char x = top->c;
    Node* tmp = top;
    top = top->next;
    free(tmp);
    return x;
}

int match(char a, char b) {
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int check(char* s) {
    initStack();
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (stackEmpty() || !match(pop(), s[i])) {
                return 0;
            }
        }
    }
    return stackEmpty();
}

int main() {
    char input[100];

    printf("Nhap vao xau mo dong ngoac: ");
    scanf("%99[^\n]", input);

    if (check(input)) {
        printf("Xau hop le\n");
    } else {
        printf("Xau khong hop le\n");
    }

    return 0;
}
