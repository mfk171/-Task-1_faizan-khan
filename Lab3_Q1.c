#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 10  // Size of the 1D array for testing

// Function to check if the position is valid
bool isValid(const int arr[], int length, int pos) {
    return (pos >= 0 && pos < length);
}

// Function to remove an element at a specified position
void remove_element(int arr[], int length, int pos) {
    if (!isValid(arr, length, pos)) {
        printf("Error: Invalid index for removal.\n");
        return;
    }

    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];  // Shift elements one position left
    }
    arr[length - 1] = 0;  // Optional: Reset the last element to 0
}

// Function to insert an element at a specified position
void insert_element(int arr[], int length, int pos, int value) {
    if (!isValid(arr, length, pos)) {
        printf("Error: Invalid index for insertion.\n");
        return;
    }

    for (int i = length - 1; i > pos; i--) {
        arr[i] = arr[i - 1];  // Shift elements one position right
    }
    arr[pos] = value;  // Insert value at the specified position
}

// Function to reshape a 1D array into a 2D array
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[nRows][nCols]) {
    if (length != nRows * nCols) {
        printf("Error: Array length does not match matrix dimensions.\n");
        return;
    }

    int index = 0;
    for (int col = 0; col < nCols; col++) {
        for (int row = 0; row < nRows; row++) {
            arr2d[row][col] = arr[index++];  // Fill matrix column by column
        }
    }
}

// Function to transpose a matrix
void trans_matrix(int nRows, int nCols, const int mat[nRows][nCols], int mat_transp[nCols][nRows]) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            mat_transp[j][i] = mat[i][j];  // Swap rows and columns
        }
    }
}

// Function to check if there are duplicates in an array
bool found_duplicate(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return true;  // Found duplicate
            }
        }
    }
    return false;  // No duplicates
}

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int nRows = 2, nCols = 5;
    int arr2d[nRows][nCols];
    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int mat_transp[3][2];

    // Test remove_element
    printf("Before removal: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    remove_element(arr, SIZE, 5);  // Remove element at index 5
    printf("After removal: ");
    for (int i = 0; i < SIZE - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Test insert_element
    insert_element(arr, SIZE - 1, 3, 100);  // Insert 100 at index 3
    printf("After insertion: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Test reshape
    reshape(arr, SIZE, nRows, nCols, arr2d);
    printf("Reshaped 2D array:\n");
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }

    // Test transpose
    trans_matrix(2, 3, mat, mat_transp);
    printf("Transposed matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", mat_transp[i][j]);
        }
        printf("\n");
    }

    // Test found_duplicate
    int arr_with_dup[SIZE] = {1, 2, 3, 4, 5, 5, 7, 8, 9, 10};
    if (found_duplicate(arr_with_dup, SIZE)) {
        printf("Duplicate found!\n");
    } else {
        printf("No duplicates found.\n");
    }

    return 0;
}
