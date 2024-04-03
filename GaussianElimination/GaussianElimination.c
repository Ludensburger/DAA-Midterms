// AUTHOR: Ryu R. Mendoza
// DATE: March 26, 2024
// DESCRIPTION:
// This program solves a system of linear equations using Gaussian Elimination method.
// The program takes a 3x4 matrix as input and performs Gaussian Elimination to solve the system of linear equations.

// Program References:
// Introduction to the Design and Analysis of Algorithms, 3rd edition - Anany Levitin

// c) Implement Gauss elimination algorithm. You may use the sample system of equations in the PDF as your test data.
#include <stdio.h>

// Row and Column size of the matrix
#define ROWS 3
#define COLS 4

int main() {

    float matrix[ROWS][COLS] = {{3, -2, 8, 9},
                                {-2, 2, 1, 3},
                                {1, 2, -3, 8}};

    // Taking input from the user
    // printf("Enter the elements of the 3x4 matrix:\n");
    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS; j++) {
    //         printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
    //         scanf("%d", &matrix[i][j]);
    //     }
    // }

    // printf("\nGiven:\n");
    // printf("x: 2x1 - x2 + x3 = 1\n");
    // printf("y: 4x1 + x2 - x3 = 5\n");
    // printf("z:  x1 + x2 + x3 = 0.\n\n");

    // Displaying the matrix
    printf("\nMatrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.0f\t", matrix[i][j]); // Use %.2f to print as float with 2 decimal places
            if (j == 2) {
                printf("| ");
            }
            // Separating columns for the coefficients
        }
        printf("\n");
    }

    // Gaussian Elimination

    // Starting at Row 2 turn the first element of the row to 0
    // Given formula: R2 = R2 - (R2C1 / R1C1) * R1
    // My Formula: R2 = -2 * R1 + R2

    // Then at Row 3 turn the first element of the row to 0
    // Given formula: R3 = R3 - (R3C1 / R1C1) * R1
    // My Formula: R3 = -1/2 * R1 + R3

    // MY IMPLEMENTATION
    // Calculate new row values
    float newRow1[COLS], newRow2[COLS];
    for (int i = 0; i < COLS; i++) {
        if (matrix[0][0] == 0) {
            printf("Mathematical error: Division by zero\n");
            return -1;
        }
        float row1Multiplier = matrix[1][0] / matrix[0][0];
        float row2Multiplier = matrix[2][0] / matrix[0][0];

        newRow1[i] = matrix[1][i] - row1Multiplier * matrix[0][i]; // Correct formula: R2 - (R2C1 / R1C1) * R1
        newRow2[i] = matrix[2][i] - row2Multiplier * matrix[0][i]; // Correct formula: R3 - (R3C1 / R1C1) * R1
    }

    // Update matrix
    for (int i = 0; i < COLS; i++) {
        matrix[1][i] = newRow1[i];
        matrix[2][i] = newRow2[i];
    }

    // GENERAL APPROACH of Implementing the Gaussian Elimination
    // for (int k = 0; k < ROWS; ++k) {
    //     for (int i = k + 1; i < ROWS; i++) {
    //         if (matrix[k][k] == 0) {
    //             printf("Mathematical error: Division by zero\n");
    //             return -1;
    //         }
    //         double factor = matrix[i][k] / matrix[k][k];
    //         for (int j = k; j < COLS; j++) {
    //             matrix[i][j] -= factor * matrix[k][j];
    //         }
    //     }
    // }

    // Displaying the matrix after Gaussian Elimination

    printf("\n");
    printf("\nPhase 1: Eliminate Row 2 and Row 3\n");
    // printf("\t Row 2: 2R1 - R2\n");
    // printf("\t Row 3: -1/2 R1 - R3\n");
    printf("\nMatrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.1f\t", matrix[i][j]); // Use %.2f to print as float with 2 decimal places
            if (j == 2) {
                printf("| ");
            }
            // Separating columns for the coefficients
        }
        printf("\n");
    }

    // Then we converting the remaining numbers below the Diagonal to 0
    // Starting at Row 3 turn the second element of the row to 0
    // Given formula: R3 = R3 - (R3C2 / R2C2) * R2

    // My Formula: -1/2 * R2 + R3
    for (int i = 0; i < COLS; ++i) {
        if (matrix[1][1] == 0) {
            printf("Mathematical error: Division by zero\n");
            return -1;
        }

        float multiplier = matrix[2][1] / matrix[1][1];

        matrix[2][i] = matrix[2][i] - multiplier * matrix[1][i]; // Correct formula: R3 - (R3Ci / R2Ci) * R2
    }

    // Displaying the matrix after Gaussian Elimination
    printf("\n");
    printf("\nPhase 2: Further eliminate Row 3\n");
    // printf("\t Row 3: -1/2 R1 + R3\n");
    printf("\nMatrix:\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.0f\t", matrix[i][j]); // Use %.2f to print as float with 2 decimal places
            if (j == 2) {
                printf("| ");
            }
            // Separating columns for the coefficients
        }
        printf("\n");
    }

    // printf("\nBack substitutions:\n");
    // printf("z = (-2) / 2 = -1, \n");
    // printf("y = (3 - (-3) z ) / 3 = 0, \n");
    // printf("x = (1 - z - (-1) y ) /2 = 1 \n\n");

    return 0;
}
