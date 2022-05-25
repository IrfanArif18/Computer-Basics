#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Modify these 2 macros to match the # of students and grades
#define STD 5 // Student(s)
#define GRD 4 // Grade(s) + 1 (1 column for GPA)

void insertGrades(float gradesPar[STD][GRD]);
void calcGPA(float gradesPar[STD][GRD]);
float avgGrades(float gradesPar[STD][GRD], int);
void printGrades(float gradesPar[STD][GRD]);

float inputRange(float, float);
int checkInt(float);


int main() {
    float grades[STD][GRD]; // rows: students; columns: grades

    system("cls");
    printf("2D ARRAY EXERCISE\n\n");

    insertGrades(grades); // Asks for user's inputs then fills grades matrix with user's inputs
    calcGPA(grades); // Calculates every student's GPA and store it to rightmost column of grades matrix
    printGrades(grades); // Prints students-grades matrix

    return 0;
}


void insertGrades(float gradesPar[STD][GRD]) {
    int i, j;

    for(i = 0; i < STD; i++) {
        printf("\nFor student #%d,\n", i + 1);
        for(j = 0; j < GRD - 1; j++) {
            printf("Insert grade %d: ", j + 1);
            gradesPar[i][j] = inputRange(0, 100); // Asks for grade inputs with limit from 0 - 100
        }
    }

}

void calcGPA(float gradesPar[STD][GRD]) {
    int i;

    // Converts each student's average grades from scale-100 to scale-4
    // then store the converted GPA to the rightmost column of each rows
    for(i = 0; i < STD; i++) {
        gradesPar[i][GRD - 1] = (float)4 / 100 * avgGrades(gradesPar, i); // Conversion and assignment
    }

}

float avgGrades(float gradesPar[STD][GRD], int stdNo) {
    float avg = 0;
    int i;

    // Calculates one student's average grades
    for(i = 0; i < GRD - 1; i++) {
        avg += gradesPar[stdNo][i];
    }

    avg /= (GRD - 1);

    return avg;
}

void printGrades(float gradesPar[STD][GRD]) {
    int i, j;

    // Prints students-grades matrix title
    printf("\n\nStudent #|");
    for(i = 0; i < GRD - 1; i++) {
        printf("Grade %d|", i + 1);
    }
    printf("GPA\t|\n");

    for(i = 0; i < STD; i++) {
        printf("\t%d|", i + 1); // Prints first column of matrix with student #

        for(j = 0; j < GRD; j++) {
            if(j == GRD - 1) {
                printf("%.2f\t|", gradesPar[i][j]); // Prints rightmost column (GPA)
            } else {

                // Prints grades according to its decimal value
                if(checkInt(gradesPar[i][j])) { // Checks whether the grade is an integer or not
                    printf("%.0f\t |", gradesPar[i][j]); // Prints one integer grade 
                } else {
                    printf("%.1f\t |", gradesPar[i][j]); // Prints one decimal grade
                }

            }
        }

        printf("\n");
    }

}


float inputRange(float low, float up) {
    float input;        

    // Asks for user's input until condition is satisfied
    while(1) {
        scanf("%f", &input);

        // Limits input range
        if(input >= low && input <= up) {
            break;
        } else {
            printf("Input must be between %.1f - %.1f.\n\n", low, up);
            printf("Please re-input: ");
        }
    }

    return input;
}

int checkInt(float numb) {
    // Checks whether number is an integer or not
    if(numb / floor(numb) == 1) {
        return 1;
    } else {
        return 0;
    }
}
