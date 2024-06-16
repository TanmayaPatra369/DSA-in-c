/*Write a program to represent the polynomial equation of single variable using single linked list and
perform the addition of two polynomial equations.*/


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to insert a new term into the polynomial
void insertTerm(struct Term** poly, int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* last = *poly;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newTerm;
    }
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
        newTerm->next = NULL;

        if (poly1 == NULL) {
            newTerm->coefficient = poly2->coefficient;
            newTerm->exponent = poly2->exponent;
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            newTerm->coefficient = poly1->coefficient;
            newTerm->exponent = poly1->exponent;
            poly1 = poly1->next;
        } else {
            if (poly1->exponent > poly2->exponent) {
                newTerm->coefficient = poly1->coefficient;
                newTerm->exponent = poly1->exponent;
                poly1 = poly1->next;
            } else if (poly2->exponent > poly1->exponent) {
                newTerm->coefficient = poly2->coefficient;
                newTerm->exponent = poly2->exponent;
                poly2 = poly2->next;
            } else {
                newTerm->coefficient = poly1->coefficient + poly2->coefficient;
                newTerm->exponent = poly1->exponent;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }

        if (result == NULL) {
            result = newTerm;
        } else {
            struct Term* last = result;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newTerm;
        }
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(struct Term* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;

        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to free the memory allocated for the polynomial
void freePolynomial(struct Term* poly) {
    struct Term* temp;

    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    // Insert terms into the first polynomial
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, -3, 1);
    insertTerm(&poly1, 2, 0);

    // Insert terms into the second polynomial
    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, 1, 1);
    insertTerm(&poly2, -7, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    struct Term* result = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    printPolynomial(result);

    // Free the allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
