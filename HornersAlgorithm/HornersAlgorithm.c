// AUTHOR: Ryu R. Mendoza
// DATE: March 26, 2024

#include <stdio.h>

// ALGORITHM Horner(P [0..n], x)
// Evaluates a polynomial at a given point by Horner’s rule
// Input: An array P[0..n] of coefficients of a polynomial of degree n,
// stored from the lowest to the highest and a number x
// Output: The value of the polynomial at x

// p←P[n]
// for i ←n − 1 downto 0 do
// p←x ∗ p + P[i]
// return p

void printCoefficients(int coefficients[], int degree) {
    printf("Coefficients: ");
    for (int i = 0; i <= degree; i++) {
        printf("%d", coefficients[i]);
        if (i < degree) {
            printf(", ");
        }
    }
    printf("\n");
}

// Function to reverse an array
int reverseArray(int *P, int arraySize) {
    // Initialize start and end pointers
    int start = 0;
    int end = arraySize;
    int temp;

    // Loop until start pointer is less than end pointer
    while (start < end) {
        // Swap elements at start and end pointers
        temp = P[start];
        P[start] = P[end];
        P[end] = temp;
        // Increment start pointer and decrement end pointer
        start++;
        end--;
    }

    // display
    // for (int i = 0; i <= n; i++) {
    //     printf("%d ", P[i]);
    // }

    printf("\n");
    return *P;
}

// My Implementation starts at index 0
// Standard, starts at index 1 where first element is the highest degree
void Horner(int coefficients[], int degree, int x) {

    int p = coefficients[0];

    for (int i = 1; i <= degree; i++) {
        p = x * p + coefficients[i];
    }

    printf("My Implementation\n");
    printf("The value of the polynomial at x = %d is: %d\n", x, p);
}

// Book Implementation starts at index n-1

void HornerBook(int coefficients[], int degree, int x) {

    // The book starts the index at the end
    // so we have to reverse the array to put the highest degree at the end
    reverseArray(coefficients, degree);

    // Here the Array is already reversed so the highest degree is at the end
    // lowest is found at the beginning

    // p is the highest degree found at index n
    int p = coefficients[degree];

    // We exclude the highest degree hence n-1
    // since n is already n-1, we have to skip the last element making it n-2
    for (int i = degree - 1; i >= 0; i--) {
        p = x * p + coefficients[i];
    }
    printf("Book Implementation\n");
    printf("The value of the polynomial at x = %d is: %d\n", x, p);
}

int main() {

    int x;

    // P(x) = 2x^4 - x^3 + 3x^2 + x - 5
    int coefficients[] = {2, -1, 3, 1, -5};

    // zero-based index
    int n = sizeof(coefficients) / sizeof(coefficients[0]) - 1;

    printf("\nGiven: P(x) = 2x^4 - x^3 + 3x^2 + x - 5\n");
    printCoefficients(coefficients, n);

    printf("\n");

    printf("Enter the value of x: ");
    scanf("%d", &x);

    if (n == 0) {
        printf("The polynomial is of degree 0\n");
        printf("The value of the polynomial at x = %d is: %d\n", x, coefficients[0]);
        return 0;
    }

    printf("\n");

    Horner(coefficients, n, x);
    HornerBook(coefficients, n, x);

    return 0;
}
