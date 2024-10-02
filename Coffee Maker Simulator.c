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
int chocolate = 75;
float total_amount = 0.0;

// Function prototypes
void makeEsp();
void makeCap();
void makeMoc();
void checkLowThresholds();
void adminMode();