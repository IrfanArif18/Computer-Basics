#include <stdio.h>
#include <stdlib.h>

void insertVec(float*, int);
float scalarMul(float*, float*, int);
void printVec(float*, int);

int inputPosInt();


int main() {
    int n;
    float product;

    system("cls");
    printf("SCALAR MULTIPLICATION OF TWO VECTORS\n\n\n");

    n = inputPosInt(); // Asks for user's input of vector dimension

    float vecA[n], vecB[n];

    printf("\nFor your first vector,\n");
    insertVec(&vecA, n); // Asks for user's input of vector A's element
    printf("\nFor your second vector,\n");
    insertVec(&vecB, n); // Asks for user's input of vector B's element

    product = scalarMul(&vecA, &vecB, n); // Calculates scalar multiplication of two vectors

    printf("\n\nOutput:\n");
    printVec(&vecA, n); // Prints vector A
    printf(" * ");
    printVec(&vecB, n); // Prints vector B
    printf("\n= %.2f", product); // Prints product

    return 0;
}


void insertVec(float* pVec, int n) {
    int i;

    for(i = 0; i < n; i++) {
        printf("Insert element(%d): ", i + 1);
        scanf("%f", (pVec + i));
    }
    
}

float scalarMul(float* pVecA, float* pVecB, int n) {
    float product = 0;
    int i;

    for(i = 0; i < n; i++) {
        product += *(pVecA + i) * *(pVecB + i);
    }

    return product;
}

void printVec(float* pVec, int n) {
    int i;

    printf("[");

	// Prints vector up to element (dimension - 1)
    for(i = 0; i < n - 1; i++) {
        printf("%.2f, ", *(pVec + i));
    }

    printf("%.2f", *(pVec + i)); // Prints vector's (dimension)-th element

    printf("]");

}


int inputPosInt() {
    int input;

    while(1) {
        printf("Insert vector dimension: ");
        scanf("%d", &input);

		// Limits input
        if(input >= 0) {
            break;
        } else {
            printf("Input must be a positive integer!\n\n");
        }
    }

    return input;
}
