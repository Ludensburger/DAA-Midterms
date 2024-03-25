# DAA-Midterms Compilation

## Project Title: Programming Lessons Compilation

This project is a compilation of various programming lessons and tasks that have been implemented. It serves as a practical application of the concepts learned during the lessons.

## Features

The program includes the following features:

- **Power Function (A):**
  This feature computes the power of a given base to a given exponent using recursion.

- **GCD Function (B):**
  This feature calculates the greatest common divisor (GCD) of two integers using recursion.

- **Insertion Sort (C):**
  This feature sorts an array of integers using the insertion sort algorithm. The user inputs the size of the array and the elements of the array, and the program outputs the sorted array.

- **Permutations (D):**
  This feature generates all permutations of a given set of integers.

- **Josephus Problem (E):**
  This feature implements the Josephus problem (Counting-out Game) algorithm to determine the survivor position.

- **Merge Sort (F):**
  This feature sorts an array of integers using the merge sort algorithm.

  - **Gaussian Elimination (G):**
  This feature solves a system of linear equations using the Gaussian Elimination method.

    **Description:**  
    This feature solves a system of linear equations using Gaussian Elimination method.
    
    **Implementation Details:**  
    The Gaussian Elimination feature is implemented in a separate C file named GaussianElimination.c, which is located in a subfolder named GaussianElimination. To use this feature, make sure that the directory hierarchy is maintained as follows:
```bash
project_folder/
├── main.c
└── GaussianElimination/
    └── GaussianElimination.c
```
The main program references the location of GaussianElimination.c to execute the Gaussian Elimination feature. If your directory structure is different, you may need to update the file paths in the code accordingly.

## How to Run

To run the program, compile the `main.c` file using a C compiler and then run the resulting executable. For example, if you're using the GCC compiler, you can use the following commands:

To compile and run the program, use the following commands:

```bash
gcc main.c -o main
./main
```

## How to Use

After running the program, follow the prompts to use each feature. For the Josephus problem, enter the total population and the number of skips when prompted. For the merge sort feature, enter the size of the array and the elements of the array when prompted.

## Future Work

Future updates may include additional features based on upcoming lessons and tasks.

##  Contributing

As this is a personal project based on individual lessons and tasks, contributions are not currently being accepted.

##  License

This project is for educational purposes and is not licensed for other use.
