#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node *next;
};

struct Node* createNode(int coeff, int pow) {
    struct Node *newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **poly, int coeff, int pow) {
    struct Node *newNode, *temp;
    newNode = createNode(coeff, pow);

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(struct Node *poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertNode(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            insertNode(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            insertNode(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Node *poly1, *poly2, *result;
    int n, coeff, pow, i;

    poly1 = NULL;
    poly2 = NULL;
    result = NULL;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    printf("Enter terms in decreasing order of power (coeff power):\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &coeff, &pow);
        insertNode(&poly1, coeff, pow);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    printf("Enter terms in decreasing order of power (coeff power):\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &coeff, &pow);
        insertNode(&poly2, coeff, pow);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    result = addPolynomials(poly1, poly2);

    printf("\nResultant Polynomial after Addition: ");
    display(result);

    return 0;
}