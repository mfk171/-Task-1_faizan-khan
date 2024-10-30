#include <stdio.h>

void remove_element(int arr[], int length, int pos) {
    // Check if pos is a valid index
    if (pos <= 0 || pos >= length) {
        printf("Invalid position: %d\n", pos);
        return;
    }

    // Shift elements to the left starting from pos (keeping arr[0] unchanged)
    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Optional: Set the last element to a default value (for visual clarity)
    arr[length - 1] = 0; // Or any value to mark "empty"
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int pos = 2;  // Index to remove (starting from 0)
    remove_element(arr, length, pos);

    printf("Array after removal: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
