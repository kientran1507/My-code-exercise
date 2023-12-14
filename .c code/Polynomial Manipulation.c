#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a term in a polynomial
struct Node {
    int coef;
    int exp;
    struct Node* next;
};

// Structure to represent a polynomial
struct Polynomial {
    int poly_id;
    struct Node* head;
};

// Function to create a new term node
struct Node* createTerm(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to add a term to a polynomial
void addTerm(struct Polynomial* poly, int coef, int exp) {
    struct Node* newNode = createTerm(coef, exp);

    if (poly->head == NULL || exp > poly->head->exp) {
        newNode->next = poly->head;
        poly->head = newNode;
    } else {
        struct Node* current = poly->head;
        struct Node* prev = NULL;

        while (current != NULL && current->exp > exp) {
            prev = current;
            current = current->next;
        }

        if (current != NULL && current->exp == exp) {
            // Update the coefficient for the existing term
            current->coef += coef;
            free(newNode);  // Free the new node since it's not needed
        } else {
            // Add a new node
            newNode->next = current;
            if (prev != NULL) {
                prev->next = newNode;
            } else {
                poly->head = newNode;
            }
        }
    }
}

// Function to print a polynomial
void printPoly(struct Polynomial* poly) {
    struct Node* current = poly->head;
    while (current != NULL) {
        printf("%d %d ", current->coef, current->exp);
        current = current->next;
    }
    printf("\n");
}

// Function to evaluate a polynomial for a given variable value
int evaluatePoly(struct Polynomial* poly, int variable_value) {
    int result = 0;
    struct Node* current = poly->head;
    while (current != NULL) {
        int term_result = current->coef;
        for (int i = 1; i <= current->exp; ++i) {
            term_result *= variable_value;
        }
        result += term_result;
        current = current->next;
    }
    return result;
}

// Function to destroy a polynomial
void destroyPoly(struct Polynomial* poly) {
    struct Node* current = poly->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}

// Function to add two polynomials and store the result in a third polynomial
void addPolynomials(struct Polynomial* poly1, struct Polynomial* poly2, struct Polynomial* resultPoly) {
    struct Node* current1 = poly1->head;
    struct Node* current2 = poly2->head;

    while (current1 != NULL || current2 != NULL) {
        int coef1 = (current1 != NULL) ? current1->coef : 0;
        int exp1 = (current1 != NULL) ? current1->exp : -1;

        int coef2 = (current2 != NULL) ? current2->coef : 0;
        int exp2 = (current2 != NULL) ? current2->exp : -1;

        if (exp1 > exp2) {
            addTerm(resultPoly, coef1, exp1);
            current1 = current1->next;
        } else if (exp1 < exp2) {
            addTerm(resultPoly, coef2, exp2);
            current2 = current2->next;
        } else {
            addTerm(resultPoly, coef1 + coef2, exp1);
            current1 = current1->next;
            current2 = current2->next;
        }
    }
}

int main() {
    struct Polynomial* polynomials[10001] = {NULL}; // Array to store polynomials

    char command[12];
    int poly_id1, poly_id2, result_poly_id, coef, exp, variable_value;

    while (1) {
        scanf("%s", command);

        if (command[0] == '*') {
            break;
        }

        if (strcmp(command, "Create") == 0) {
            scanf("%d", &poly_id1);
            if (polynomials[poly_id1] == NULL) {
                polynomials[poly_id1] = (struct Polynomial*)malloc(sizeof(struct Polynomial));
                polynomials[poly_id1]->poly_id = poly_id1;
                polynomials[poly_id1]->head = NULL;
            }
        } else if (strcmp(command, "AddTerm") == 0) {
            scanf("%d %d %d", &poly_id1, &coef, &exp);
            if (polynomials[poly_id1] == NULL) {
                polynomials[poly_id1] = (struct Polynomial*)malloc(sizeof(struct Polynomial));
                polynomials[poly_id1]->poly_id = poly_id1;
                polynomials[poly_id1]->head = NULL;
            }
            addTerm(polynomials[poly_id1], coef, exp);
        } else if (strcmp(command, "EvaluatePoly") == 0) {
            scanf("%d %d", &poly_id1, &variable_value);
            if (polynomials[poly_id1] == NULL) {
                printf("0\n");
            } else {
                printf("%d\n", evaluatePoly(polynomials[poly_id1], variable_value));
            }
        } else if (strcmp(command, "PrintPoly") == 0) {
            scanf("%d", &poly_id1);
            if (polynomials[poly_id1] != NULL) {
                printPoly(polynomials[poly_id1]);
            }
        } else if (strcmp(command, "Destroy") == 0) {
            scanf("%d", &poly_id1);
            if (polynomials[poly_id1] != NULL) {
                destroyPoly(polynomials[poly_id1]);
                polynomials[poly_id1] = NULL;
            }
        } else if (strcmp(command, "AddPoly") == 0) {
            scanf("%d %d %d", &poly_id1, &poly_id2, &result_poly_id);
            if (polynomials[result_poly_id] == NULL) {
                polynomials[result_poly_id] = (struct Polynomial*)malloc(sizeof(struct Polynomial));
                polynomials[result_poly_id]->poly_id = result_poly_id;
                polynomials[result_poly_id]->head = NULL;
            }
            addPolynomials(polynomials[poly_id1], polynomials[poly_id2], polynomials[result_poly_id]);
        }
    }
    return 0;
}
