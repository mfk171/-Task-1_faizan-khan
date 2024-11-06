#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BALANCE 1000

void process_transactions(int *transactions, int length, int **tobeprocessed, int *tobeprocessed_count) {
    int balance = INITIAL_BALANCE;
    *tobeprocessed_count = 0;
    
    // Dynamically allocate memory for the tobeprocessed array
    *tobeprocessed = (int *)malloc(length * sizeof(int));
    
    for (int i = 0; i < length; i++) {
        int transaction = transactions[i];
        
        // If a withdrawal exceeds the current balance, store it in tobeprocessed
        if (transaction < 0 && balance + transaction < 0) {
            printf("Transaction of %d AED is invalid due to insufficient balance.\n", transaction);
            (*tobeprocessed)[*tobeprocessed_count] = transaction;
            (*tobeprocessed_count)++;
        } else {
            // Process valid transactions
            balance += transaction;
            printf("Processed transaction: %d AED, New balance: %d AED\n", transaction, balance);
            
            // Stop processing if the balance reaches 0
            if (balance == 0) {
                printf("Balance reached 0. No further transactions will be processed.\n");
                break;
            }
        }
    }
    
    // Print the final balance and unprocessed transactions
    printf("\nFinal balance: %d AED\n", balance);
    printf("Unprocessed transactions: ");
    for (int i = 0; i < *tobeprocessed_count; i++) {
        printf("%d ", (*tobeprocessed)[i]);
    }
    printf("\n");

    // Free dynamically allocated memory for tobeprocessed
    free(*tobeprocessed);
}

int main() {
    // Example transactions array
    int transactions[] = {200, -150, -500, -400, -50, -200, 300}; 
    int length = sizeof(transactions) / sizeof(transactions[0]);
    
    int *tobeprocessed = NULL;   // Pointer to dynamically allocated memory for unprocessed transactions
    int tobeprocessed_count = 0; // To keep track of unprocessed transactions count
    
    process_transactions(transactions, length, &tobeprocessed, &tobeprocessed_count);
    
    return 0;
}

