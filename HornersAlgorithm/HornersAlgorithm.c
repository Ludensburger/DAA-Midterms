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

// My Implementation starts at index 0
// Standard, starts at index 1 where first element is the highest degree
void Horner(int P[], int n, int x) {

    int p = P[0];

    for (int i = 1; i <= n; i++) {
        p = x * p + P[i];
    }

    printf("My Implementation\n");
    printf("The value of the polynomial at x is: %d\n", p);
}

int reverseArray(int *P, int n) {
    int start = 0;
    int end = n;
    int temp;

    while (start < end) {
        temp = P[start];
        P[start] = P[end];
        P[end] = temp;
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

// Book Implementation starts at index n-1

void HornerBook(int P[], int n, int x) {

    // The book starts the index at the end
    // so we have to reverse the array to put the highest degree at the end
    reverseArray(P, n);

    // Here the Array is already reversed so the highest degree is at the end
    // lowest is found at the beginning

    // p is the highest degree found at index n
    int p = P[n];

    // We exclude the highest degree hence n-1
    // since n is already n-1, we have to skip the last element making it n-2
    for (int i = n - 1; i >= 0; i--) {
        p = x * p + P[i];
    }
    printf("Book Implementation\n");
    printf("The value of the polynomial at x is: %d\n", p);
}

int main() {

    int x;
    int P[] = {
        2,
        -1,
        3,
        1,
        -5};

    // zero-based index
    int n = sizeof(P) / sizeof(P[0]) - 1;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    if (n == 0) {
        printf("The polynomial is of degree 0\n");
        printf("The value of the polynomial at x is: %d\n", P[0]);
        return 0;
    }

    printf("Given: P(x) = 2x^4 - x^3 + 3x^2 + x - 5\n");

    // printf("Given: P(x) = 2x^3 - x^2 + x + 1\n");

    Horner(P, n, x);
    HornerBook(P, n, x);

    return 0;
}
