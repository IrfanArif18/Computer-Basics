#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float re;
    float im;
} complex;

 complex insertNum();
 void printNum(complex*);
 complex add(complex, complex);
 complex mul(complex, complex);
 int checkInt(float);

int main() {
    complex a, b, addOut, mulOut;
    
    system("cls");
    printf("PROGRAM PENJUMLAHAN DAN PERKALIAN BILANGAN KOMPLEKS\n\n");

    printf("\nUntuk bilangan kompleks pertama,\n");
    a = insertNum();
    printf("\nUntuk bilangan kompleks kedua,\n");
    b = insertNum();

    printf("\n\nAnda memasukkan:");
    printf("\na = ");
    printNum(&a);
    printf("\nb = ");
    printNum(&b);

    addOut = add(a, b);
    mulOut = mul(a, b);

    printf("\n\n\nOutput:");
    printf("\na + b = ");
    printNum(&addOut);
    printf("\na * b = ");
    printNum(&mulOut);

    return 0;
}

complex insertNum() {
    complex cIn;

    printf("Masukkan besaran komponen real: ");
    scanf("%f", &cIn.re);
    printf("Masukkan besaran komponen imajiner: ");
    scanf("%f", &cIn.im);

    return cIn;
}

void printNum(complex* c) {
    if(checkInt(c->re) == 0) {
        printf("%.3f", c->re);
    } else {
        printf("%.0f", c->re);
    }
    
    if(c->im >= 0) {
        printf(" + ");
    } else {
        printf(" - ");
    }

    if(checkInt(c->im) == 0) {
        printf("i%.3f", fabs(c->im));
    } else {
        printf("i%.0f", fabs(c->im));
    }
    
}

complex add(complex cA, complex cB) {
    complex sum;

    sum.re = cA.re + cB.re;
    sum.im = cA.im + cB.im;

    return sum;
}

complex mul(complex cA, complex cB) {
    complex mul;

    mul.re = (cA.re * cB.re) - (cA.im * cB.im);
    mul.im = (cA. re * cB.im) + (cA.im * cB.re);

    return mul;
}

int checkInt(float numb) {
    if(numb / floor(numb) == 1) {
        return 1;
    } else {
        return 0;
    }
}