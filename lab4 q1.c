#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int is_valid_float(const char *str);
void process_file(const char *input_filename, const char *output_filename);
void create_sample_file(const char *filename);

int main() {
    const char *input_filename = "data.txt";
    const char *output_filename = "valid_floats.txt";

    // Create a sample input file with given data
    create_sample_file(input_filename);

    // Process the input file and write valid floats to the output file
    process_file(input_filename, output_filename);

    return 0;
}

// Function to create a sample file with provided data
void create_sample_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating sample file");
        exit(EXIT_FAILURE);
    }

    // Write the sample data to the file
    fprintf(file, "A 10.0 12.0 14.0 B 20.0 22.0 24.0 C30.0 32.0 34.0 D 40.0 42.0 44.7 E\n");
    fclose(file);
}

// Function to check if a string represents a valid float
int is_valid_float(const char *str) {
    char *endptr;
    strtod(str, &endptr);

    // Check if the conversion consumed the entire string and it's not empty
    return (*endptr == '\0' && endptr != str);
}

// Function to process the input file
void process_file(const char *input_filename, const char *output_filename) {
    FILE *input_file, *output_file;
    char buffer[256];
    int invalid_count = 0;

    // Open the input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    // Process the file line by line
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        char *token = strtok(buffer, " \t\n");

        while (token != NULL) {
            if (is_valid_float(token)) {
                // Write valid float to the output file
                fprintf(output_file, "%s\n", token);
            } else {
                // Increment the invalid count
                invalid_count++;
            }
            token = strtok(NULL, " \t\n");
        }
    }

    // Check for errors during reading
    if (ferror(input_file)) {
        perror("Error reading input file");
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    // Display the count of invalid values
    printf("Number of invalid float values: %d\n", invalid_count);
}
