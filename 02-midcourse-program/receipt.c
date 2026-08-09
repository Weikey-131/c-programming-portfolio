/*
Purpose: Read item quantities and write receipt.txt.
Fixed prices:
Coffee $3.00, Sandwich $7.50, Cookie $2.00
Tax 8.875%, discount 10% when subtotal > $50.00
*/

#include <stdio.h>

double calculateSubtotal(int coffeeQty, int sandwichQty, int cookieQty);
double calculateTax(double subtotal);
double calculateDiscount(double subtotal);
double calculateFinalTotal(double subtotal, double tax, double discount);

int main(void)
{
    int coffeeQty = 0;
    int sandwichQty = 0;
    int cookieQty = 0;

    // Read three integer quantities in this order: coffee, sandwich, cookie.
    printf("Enter coffee quantity: ");
    scanf("%d", &coffeeQty);

    printf("Enter sandwich quantity: ");
    scanf("%d", &sandwichQty);

    printf("Enter cookie quantity: ");
    scanf("%d", &cookieQty);


    /* Call all four calculation functions. */
    double subtotal = calculateSubtotal(coffeeQty, sandwichQty, cookieQty);

    double tax = calculateTax(subtotal);

    double discount = calculateDiscount(subtotal);

    double finalTotal = calculateFinalTotal(subtotal, tax, discount);

    /* Open receipt.txt with "w" and check for NULL. */
     // Create a file pointer.
    FILE *fp = NULL;
     // Open receipt.txt in write mode.
    fp = fopen("receipt.txt", "w");
     // Check if file opened successfully.
    if (fp == NULL)
    {
        printf("Error: could not open receipt.txt\n");
        return 1;
    }


    /*Use fprintf() to include these labels:
       Coffee
       Sandwich
       Cookie
       Subtotal
       Tax
       Discount
       Final total
    */
    fprintf(fp, "------ Receipt ------\n");

    fprintf(fp, "Coffee: %d\n", coffeeQty);

    fprintf(fp, "Sandwich: %d\n", sandwichQty);

    fprintf(fp, "Cookie: %d\n", cookieQty);

    fprintf(fp, "Subtotal: $%.2f\n", subtotal);

    fprintf(fp, "Tax: $%.2f\n", tax);

    fprintf(fp, "Discount: $%.2f\n", discount);

    fprintf(fp, "Final total: $%.2f\n", finalTotal);


    /* Close the file and print a saved message. */
    fclose(fp);
    //the receipt was saved
    printf("The receipt was saved\n");

    (void)coffeeQty;
    (void)sandwichQty;
    (void)cookieQty;
    return 0;
}

double calculateSubtotal(int coffeeQty, int sandwichQty, int cookieQty)
{
  /// calculate each items's price
 double coffeeTotal = coffeeQty * 3.00;
 double sandwichTotal = sandwichQty * 7.50;
 double cookieTotal = cookieQty * 2.00;
    (void)coffeeQty;
    (void)sandwichQty;
    (void)cookieQty;
   
    return coffeeTotal + sandwichTotal + cookieTotal;// add all item prices together
}

double calculateTax(double subtotal)
{
   ///set the taxrate to be 8.875%
    double taxRate = 0.08875;

    // Calculate tax amount.
    double tax = subtotal * taxRate;

   
    (void)subtotal;
    return tax;
}

double calculateDiscount(double subtotal)
{
   //set the discountrate to be 10%
       double discountRate = 0.10;

    // Calculate discount only when subtotal is greater than $50.
    if (subtotal > 50.00)
    {
        double discount = subtotal * discountRate;

        return discount;
    }

    (void)subtotal;
    return 0.0;//// No discount when subtotal is $50 or less.
}

double calculateFinalTotal(double subtotal, double tax, double discount)
{
  
    // Add tax first.
    double totalBeforeDiscount = subtotal + tax;

    // Subtract discount.
    double finalTotal = totalBeforeDiscount - discount;

    (void)subtotal;
    (void)tax;
    (void)discount;
    return finalTotal;
}
