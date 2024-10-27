// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ESP_BEANS 8      
#define ESP_WATER 30    
#define ESP_PRICE 5.0 

#define CAP_BEANS 8    
#define CAP_WATER 30   
#define CAP_MILK 70    
#define CAP_PRICE 7.5

#define MOC_BEANS 8       
#define MOC_WATER 39    
#define MOC_MILK 160    
#define MOC_SYRUP 30    
#define MOC_PRICE 9.0

#define ADMIN_PASSWORD "admin077"
#define LOW_THRESHOLD_BEANS 10
#define LOW_THRESHOLD_WATER 50
#define LOW_THRESHOLD_MILK 100
#define LOW_THRESHOLD_SYRUP 150

// Variables to hold ingredient quantities
int coffee_beans = 50;
int water = 100;
int milk = 150;
int syrup = 175;
float total_sales = 0.0;

// Function prototypes
void makeEsp();
void makeCap();
void makeMoc();
void checkLowThresholds();
void adminMode();
void orderCoffee();
void displayIngredients();
void replenishIngredients();
void changePrices();
void updateSales(float amount);

int main() {
    int choice;
    while (1) {
        printf("\nCoffee Maker Simulator\n");
        printf("1. Order a coffee\n");
        printf("2. Admin mode\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                orderCoffee();
                break;
            case 2:
                adminMode();
                break;
            case 3:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Admin mode function with a menu loop
void adminMode() {
    char password[20];
    int choice;
    
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(password, ADMIN_PASSWORD) == 0) {
        while (1) {
            printf("\n--- Admin Menu ---\n");
            printf("1. Display ingredient levels\n");
            printf("2. Replenish ingredients\n");
            printf("3. Change coffee prices\n");
            printf("4. Reset total sales\n");
            printf("0. Exit admin mode\n");
            printf("Select an option: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    displayIngredients();
                    break;
                case 2:
                    replenishIngredients();
                    break;
                case 3:
                    changePrices();
                    break;
                case 4:
                    total_sales = 0.0;
                    printf("Total sales reset. Don't forget to collect the money!\n");
                    break;
                case 0:
                    return; // Exit admin mode
                default:
                    printf("Invalid choice. Try again.\n");
            }
        }
    } else {
        printf("Incorrect password.\n");
    }
}

// Function to display current ingredient levels and total sales
void displayIngredients() {
    printf("\n--- Ingredient Levels ---\n");
    printf("Coffee Beans: %d grams\n", coffee_beans);
    printf("Water: %d ml\n", water);
    printf("Milk: %d ml\n", milk);
    printf("Syrup: %d ml\n", syrup);
    printf("Total sales: AED %.2f\n", total_sales);
}

// Function to refill ingredients with random amounts
void replenishIngredients() {
    srand(time(0)); // Seed for random numbers
    coffee_beans = rand() % 100 + 50; // Random between 50 and 150 grams
    water = rand() % 500 + 200;       // Random between 200 and 700 ml
    milk = rand() % 300 + 100;        // Random between 100 and 400 ml
    syrup = rand() % 100 + 50;        // Random between 50 and 150 ml
    printf("Ingredients replenished.\n");
}

// Function to change coffee prices (optional feature)
void changePrices() {
    printf("This feature is not implemented in this example.\n");
}

// Function to update total sales after a purchase
void updateSales(float amount) {
    total_sales += amount;
}

// Additional functions to make different types of coffee
void makeEsp() {
    coffee_beans -= ESP_BEANS;
    water -= ESP_WATER;
    printf("Making Espresso...\n");
    checkLowThresholds();
}

void makeCap() {
    coffee_beans -= CAP_BEANS;
    water -= CAP_WATER;
    milk -= CAP_MILK;
    printf("Making Cappuccino...\n");
    checkLowThresholds();
}

void makeMoc() {
    coffee_beans -= MOC_BEANS;
    water -= MOC_WATER;
    milk -= MOC_MILK;
    syrup -= MOC_SYRUP;
    printf("Making Mocha...\n");
    checkLowThresholds();
}

// Function to check ingredient levels and alert if they are low
void checkLowThresholds() {
    if (coffee_beans < LOW_THRESHOLD_BEANS) {
        printf("Warning: Low coffee beans!\n");
    }
    if (water < LOW_THRESHOLD_WATER) {
        printf("Warning: Low water!\n");
    }
    if (milk < LOW_THRESHOLD_MILK) {
        printf("Warning: Low milk!\n");
    }
    if (syrup < LOW_THRESHOLD_SYRUP) {
        printf("Warning: Low syrup!\n");
    }
}

// Function to handle coffee ordering
void orderCoffee() {
    int selection, confirm;
    float price = 0.0;

    printf("\n--- Coffee Menu ---\n");

    // Check availability and display options
    if (coffee_beans >= ESP_BEANS && water >= ESP_WATER) {
        printf("1. Espresso - AED %.2f\n", ESP_PRICE);
    } else {
        printf("1. Espresso - Not available\n");
    }

    if (coffee_beans >= CAP_BEANS && water >= CAP_WATER && milk >= CAP_MILK) {
        printf("2. Cappuccino - AED %.2f\n", CAP_PRICE);
    } else {
        printf("2. Cappuccino - Not available\n");
    }

    if (coffee_beans >= MOC_BEANS && water >= MOC_WATER && milk >= MOC_MILK && syrup >= MOC_SYRUP) {
        printf("3. Mocha - AED %.2f\n", MOC_PRICE);
    } else {
        printf("3. Mocha - Not available\n");
    }

    printf("Select coffee (0 to exit): ");
    scanf("%d", &selection);

    switch (selection) {
        case 0:
            return;
        case 1:
            if (coffee_beans >= ESP_BEANS && water >= ESP_WATER) {
                price = ESP_PRICE;
                makeEsp();
            } else {
                printf("Espresso unavailable.\n");
                return;
            }
            break;
        case 2:
            if (coffee_beans >= CAP_BEANS && water >= CAP_WATER && milk >= CAP_MILK) {
                price = CAP_PRICE;
                makeCap();
            } else {
                printf("Cappuccino unavailable.\n");
                return;
            }
            break;
        case 3:
            if (coffee_beans >= MOC_BEANS && water >= MOC_WATER && milk >= MOC_MILK && syrup >= MOC_SYRUP) {
                price = MOC_PRICE;
                makeMoc();
            } else {
                printf("Mocha unavailable.\n");
                return;
            }
            break;
        default:
            printf("Invalid selection.\n");
            return;
    }

    // Confirm order with user
    printf("You selected coffee priced at AED %.2f. Confirm? (1 for yes, 0 for no): ", price);
    scanf("%d", &confirm);
    if (confirm != 1) {
        printf("Order cancelled.\n");
        return;
    }

    // Payment process
    float paid = 0.0, coin;
    while (paid < price) { // Loop until full payment is made
        printf("Insert coin (1 or 0.5 AED): ");
        scanf("%f", &coin);
        if (coin == 1 || coin == 0.5) {
            paid += coin;
            printf("Total paid: AED %.2f\n", paid);
        } else {
            printf("Invalid coin. Please insert a valid coin.\n");
        }
    }

    // Print receipt with change amount
    printf("Coffee purchased. You paid AED %.2f. Change: AED %.2f\n", paid, paid - price);
    updateSales(price); // Update total sales
}

