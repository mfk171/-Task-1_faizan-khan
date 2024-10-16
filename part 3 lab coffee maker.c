#include <stdio.h>

#define ESP_BEANS 8      
#define ESP_WATER 30    

#define CAP_BEANS 8    
#define CAP_WATER 30   
#define CAP_MILK 70    

#define MOC_BEANS 8       
#define MOC_WATER 39    
#define MOC_MILK 160    
#define MOC_SYRUP 30    

int main() {
  // Example usage
 printf("To make a cup of Esp, you need:\n");
 printf("%d grams of coffee beans\n", ESP_BEANS);
  printf("%d milliliters of water\n", ESP_WATER);
 printf("\nTo make a cup of Cap, you need:\n");
 printf("%d grams of coffee beans\n", CAP_BEANS);
 printf("%d milliliters of water\n", CAP_WATER);
 printf("%d milliliters of milk\n", CAP_MILK);
 printf("\nTo make a cup of Moc, you need:\n");
 printf("%d grams of coffee beans\n", MOC_BEANS);
  printf("%d milliliters of water\n", MOC_WATER);
 printf("%d milliliters of milk\n", MOC_MILK);
 printf("%d milliliters of chocolate syrup\n", MOC_SYRUP);
 return 0;
}


#define ADMIN_PASSWORD "admin077"
#define LOW_THRESHOLD_BEANS 10
#define LOW_THRESHOLD_WATER 50
#define LOW_THRESHOLD_MILK 100
#define LOW_THRESHOLD_CHOCOLATE 150

// Variables to hold ingredient quantities
int beans = 50;
int water = 100;
int milk = 150;
int chocolate = 175;
float total_amount = 0.0;

// Function prototypes
void makeEsp();
void makeCap();
void makeMoc();
void checkLowThresholds();
void adminMode();      


int main() {
int choice;
while (1) {
printf("\n Coffee Maker Simulator\n");
printf("1. Order a coffee\n");
printf("2. admin mode\n");
printf("3. Exit\n");
printf("Select an option: ");
scanf("%d",&choice);

switch (choice) {
case 1:
orderCoffee();
break;
case 2:
adminMode();
break;
case 3:
printf("Exiting \n");
exit(0);
default:
printf("Invalid choice. Please try again.\n"); }
}
return 0;
}

// Function to handle coffee ordering
void orderCoffee() {
int selection, confirm;
float price = 0.0;
printf("\n--- Coffee Menu ---\n");

// Check availability and display options
if (coffee_Beans >= ESP_BEANS && water >= ESP_WATER) {
printf ("1. Esp - AED %.3f\n", ESP_PRICE);
} else {
printf ("1. Esp - not available\n");
}

if (coffee_Beans >= CAP_BEANS && water >= CAP_WATER && milk >= CAP_MILK) {
printf("2. Cap - AED %.3f\n", CAP_PRICE);
} else {
printf ("2. Cap - not available\n");
}
if (coffee_Beans >= MOC_BEANS && water >= MOC_WATER && milk >= MOC_MILK && syrup >= MOC_SYRUP) {
printf("3. Moc - AED %.3f\n", MOC_PRICE);
} else {
printf("3. Moc -not available\n");
}

printf("Select coffee (0 to exit): ");
scanf("%d", &selection);

switch (selection) {
case 0:

if (coffee_beans >= CAP_BEANS && water >= CAP_WATER && milk >= CAPPUCCINO_MILK) {
printf("2. Cap - AED %.3f\n", CAP_PRICE);
} else {
printf("2. Cap - Unavailable\n");
}
if (coffee_beans >= MOC_BEANS && water >= MOC_WATER && milk >= MOC_MILK && syrup >= MOC_SYRUP) {
printf("3. Moc - AED %.2f\n", MOC_PRICE);
} else {
printf("3. Moc - Unavailable\n");
}
printf("Select coffee (0 to exit): ");
scanf("%d", &selection);
switch (selection) {
case 0:
return; // exit
case 1:
if (coffee_beans >= ESP_BEANS && water >= ESP_WATER) {
price = ESP_PRICE;
} else {
printf("Esp unavailable.\n");
return;
}
break;
case 2:
if (coffee_beans >= CAP_BEANS && water >= CAP_WATER && milk >= CAP_MILK) {
price = CAP_PRICE;
} else {
printf("Cap unavailable.\n");
  return;
 }
break;
case 3:
 if (coffee_beans >= MOC_BEANS && water >= MOC_WATER && milk >= MOC_MILK && syrup >= MOC_SYRUP) {
price = MOC_PRICE;
} else {
printf("Moc unavailable.\n");
return;
 }
break;
default:
printf("Invalid selection.\n");
 return;
 }





