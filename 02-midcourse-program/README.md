# Artifact 2 — Mid-Course Program

program name : receipt writer

## Program Purpose
This program creates a coffee shop receipt.
It reads the quantities of coffee, sandwiches, and cookies from the user. 
The initial price of these items as follows：
Coffee $3.00, Sandwich $7.50, Cookie $2.00
Tax 8.875%, discount 10% when subtotal > $50.00
The program calculates the subtotal, tax, discount, and final total.
The final receipt is written into a file named receipt.txt.

This program demonstrates the use of functions and file handling in C.

## Files
-'receipt_writer.c'
Contains the main function and all calculation functions:
- calculateSubtotal()
- calculateTax()
- calculateDiscount()
- calculateFinalTotal()

The program handles user input, performs calculations, and writes the receipt file.

## Compile and Run

```bash
gcc -Wall -Wextra -std=c11 receipt.c -o receipt
./receipt
```

## Sample Input and Output
/////Normal Case

1.Input:

Enter coffee quantity: 5
Enter sandwich quantity: 8
Enter cookie quantity: 3

2.Output:

The receipt was saved

3.The generated receipt.txt file:

------ Receipt ------
Coffee: 5
Sandwich: 8
Cookie: 3
Subtotal: $81.00
Tax: $7.19
Discount: $8.10
Final total: $80.09

/////Edge Case

1.Input:

Enter coffee quantity: 0
Enter sandwich quantity: 0
Enter cookie quantity: 0

2.Output:

The receipt was saved

3.
Subtotal: $0.00
Tax: $0.00
Discount: $0.00
Final total: $0.00


## What I Learned

This program helped me understand how to break down a large program into smaller functions and achieve the program's overall objective through the interactions between them.

I learned how to use file-handling functions in C—such as `fopen()`, `fprintf()`, and `fclose()`—to generate receipt files.

During the testing phase, I performed standard data tests as well as a test for the edge case where the quantities of all items were zero.

One bug I fixed involved ensuring that the discount was applied only when the subtotal exceeded $50.00; prior to the fix, the program might have incorrectly applied the discount to orders with lower totals..

