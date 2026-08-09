#include <stdio.h>

int main(void) {
    double temp;
    int zero_count = 0;
    int positive_count = 0;
    int negative_count = 0;
    double positive_sum = 0.0;
    double negative_sum = 0.0;  // set the variables
    
    for (int i = 0; i < 15; i++) {        // "for" loop that runs 15 times to read one temperature each time with scanf
           
        printf("Enter temperature %d: ", i + 1); // print the input of the temperature like "Enter temperature 1: ", "Enter temperature 2: ", etc.
        scanf("%lf", &temp); //read the temperature input from the user and store it in the variable "temp"
        
        if (temp > 0) {
            positive_sum += temp;   // keep counting positive sum
            positive_count++;
        } else if (temp < 0) {    
            negative_sum += temp;  // keep counting negative sum  
            negative_count++;
        } else {
            zero_count++; 
        }
    }
    printf("\n--- Results ---\n");
    printf("Zero count: %d\n", zero_count); // print zero_count

        if (positive_count > 0) {   // check if there are any positive values to avoid division by zero
        printf("positive average: %.2f\n", positive_sum / positive_count); // print the positive average
        } else {
        printf("positive average: none\n");
        }


        if (negative_count > 0) {  // check if there are any negative values to avoid division by zero
        printf("negative average: %.2f\n", negative_sum / negative_count); // print the negative average
        } else {
        printf("negative average: none\n");
        }
    
    

    return 0;
} // 
