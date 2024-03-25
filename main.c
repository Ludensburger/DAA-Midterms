#include <stdio.h>
#include <stdlib.h> // for system() function

void merge(const int *leftArr, int leftSize, const int *rightArr, int rightSize, int *arr);

// A
int PowerFunction(int base, int exponent) {

    if (exponent == 0) {
        return 1;
    } else {
        return base * PowerFunction(base, exponent - 1);
    }
}

// B
int GCDFunction(int a, int b) {

    if (a == 0) {
        return b;
    } else {
        return GCDFunction(b % a, a);
    }
}

// C
int InsertionSort(int *array, int size) {

    // start at index 1
    for (int i = 1; i < size; i++) {
        // key is the current element
        int key = array[i];
        // slow pointer j (behind i)
        int j = i - 1;

        // keep moving the elements to the right until we find the correct position for the key
        // or until we reach the beginning of the array

        // keep j inside the bounds of array, so it doesnt reach negative index and
        // keep moving the elements to the right until we find the correct position for the key
        while (j >= 0 && array[j] > key) {
            // update the element to the right with the current element
            // update j's next value with j's current value
            array[j + 1] = array[j];
            j = j - 1; // then move j to the left
        }

        array[j + 1] = key;
    }

    return *array;
}

// helper function for permutations
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// helper function for permutations
void printPermutation(int array[], int size) {
    printf("(");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(")");
}

// D
void Permutations(int array[], int start, int end) {
    if (start == end) {
        printPermutation(array, end + 1);
        printf(", \n"); // print a comma after each permutation
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&array[start], &array[i]);
        Permutations(array, start + 1, end);
        swap(&array[start], &array[i]); // backtrack
    }
}

// E
int Josephus(int n, int k) {
    int i;
    int a[n];
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    printf("Currently alive: ");
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("\n");

    int index = 0;
    int count = 0;
    int remaining = n;

    while (remaining > 1) {
        if (a[index] != 0) {
            count++;
            if (count == k) {
                printf("Person at index %d is dead.\n", a[index]); // print death message
                a[index] = 0;
                count = 0;
                remaining--;
            }
        }
        index++;
        if (index == n) {
            index = 0;
        }
    }

    for (i = 0; i < n; i++) {
        if (a[i] != 0) {
            return a[i];
        }
    }
    return -1;
}

// F
void mergeSort(int *arr, int length) {

    // Base Case: If array length is 1 or less, it's already sorted
    if (length <= 1) {
        return;
    }

    // -for readability purposes
    // -Calculate mid-point and sizes of left and right subarrays
    int mid = length / 2;
    int leftSize = mid;
    int rightSize = length - mid;

    // -or pwede ra diritso leftArr[mid] & rightArr[length - mid]
    // -Create left and right subarrays
    int leftArr[leftSize];
    int rightArr[rightSize];

    // Split the array into left and right subarrays
    int i = 0; // left array
    int j = 0; // right array
    for (; i < length; i++) {
        //      -copy original array to left array
        //      -Copy elements to left array if before mid, else to right array
        if (i < mid) {
            leftArr[i] = arr[i];

            //      copy original array to right array
        } else {
            rightArr[j++] = arr[i];
            //            j++;
        }
    }

    //  -Recursion part
    //  -Recursively sort left and right subarrays
    mergeSort(leftArr, mid);                            // divide left
    mergeSort(rightArr, length - mid);                  // divide right
    merge(leftArr, leftSize, rightArr, rightSize, arr); // Merge sorted subarrays
}

void printMerge(int *arr, int length) {

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {

        printf("%d", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }

    printf("\n");
}

// Helper function/definition
void merge(const int *leftArr, int leftSize, const int *rightArr, int rightSize, int *arr) {

    int i = 0, l = 0, r = 0;

    //  -Check conditions for merging
    //  -while there's elements in the left and right arrays, we will continue adding elements to the original array array
    //  -Merge left and right subarrays into arr
    while (l < leftSize && r < rightSize) {

        //      -check which element is smaller
        //      -Compare elements from left and right subarrays and merge them into arr
        if (leftArr[l] < rightArr[r]) {
            arr[i++] = leftArr[l++];
            // i++;
            // l++;
        } else {
            arr[i++] = rightArr[r++];
            // i++;
            // r++;
        }
    }
    //  Copy remaining elements from left subarray, if any
    while (l < leftSize) {
        arr[i++] = leftArr[l++];
        // i++;
        // l++;
    }
    //  Copy remaining elements from right subarray, if any
    while (r < rightSize) {
        arr[i++] = rightArr[r++];
        // i++;
        // r++;
    }
}

int main() {

    char op;

    // Main Menu
    do {

        int result = 0; // to clear result everytime it comes back to Main Menu

        printf("Op: ");
        scanf(" %c", &op);

        switch (op) {
            // Power Function
        case 'a': {

            int a; // base
            int x; // exponent

            printf("POWER FUNCTION\n ");

            // input base
            printf("Enter a base: ");
            scanf("%d", &a);

            // input exponent
            printf("Enter a exponent: ");
            scanf("%d", &x);

            result = PowerFunction(a, x); // pass a as base and x as exponent

            printf("Result: %d\n", result); // show result
            break;
        }
            // GCD Function
        case 'b': {
            int a, b;

            printf("GCD\n ");

            printf("Enter a: ");
            scanf("%d", &a);

            printf("Enter b: ");
            scanf("%d", &b);

            result = GCDFunction(a, b);
            printf("Result: %d\n", result); // show result
            break;
        }

        case 'c': {

            printf("INSERTION SORT\n ");

            int size;

            printf("Enter size: ");
            scanf("%d", &size);

            int array[size];

            // populate array

            for (int i = 0; i < size; i++) {
                printf("Enter element [%d]: ", i);
                scanf("%d", &array[i]);
            }

            InsertionSort(array, size);

            for (int i = 0; i < size; i++) {
                printf("%d", array[i]);
                if (i < size - 1) {
                    printf(", ");
                }
            }
            printf("\n");
            break;
        }

        case 'd': {

            int n;

            printf("PERMUTATIONS\n ");

            printf("Enter n: ");
            scanf("%d", &n);

            int array[n];
            for (int i = 0; i < n; i++) {
                array[i] = i + 1;
            }

            printf("Permutations of %d: {\n", n);
            Permutations(array, 0, n - 1);
            printf("}\n");
            break;
        }

        case 'e': {

            int n;
            int k;

            printf("JOSEPHUS PROBLEM (Counting-out Game)\n ");

            printf("Enter population: ");
            scanf("%d", &n);

            printf("Enter skips: ");
            scanf("%d", &k);

            int survivor = Josephus(n, k);
            printf("Survivor: %d\n", survivor);
            break;
        }

        case 'f': {

            int size;

            printf("MERGE SORT\n ");

            printf("Enter size: ");
            scanf("%d", &size);

            int arr[size];

            for (int i = 0; i < size; i++) {
                printf("Enter element [%d]: ", i);
                scanf("%d", &arr[i]);
            }

            // call mergeSort function to sort the array
            mergeSort(arr, size);

            // show the sorted array
            printMerge(arr, size);

            break;
        }

        case 'g': {
            printf("Running GaussianElimination.c...\n");
            // Execute the compiled GaussianElimination program
            int result = system("\"C:\\Users\\hp\\Desktop\\Ryu Files\\Codes\\C-Programming\\CPP\\Midterms-AlgoStudy\\GaussianElimination\\GaussianElimination.exe\"");
            if (result == -1) {
                perror("Error running GaussianElimination.c");
            } else {
                printf("GaussianElimination.c execution finished with return code: %d.\n", result);
            }
            break;
        }

            // EXIT
        case 'x': {
            printf("Exiting...\n");
            break;
        }
        }
    } while (op != 'x');

    return 0;
}