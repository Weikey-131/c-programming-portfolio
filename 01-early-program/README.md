# Artifact 1 — Early Program
Program name : Temperature Analyzer

## Program Purpose

This program reads exactly 15 temperature values from the user.
It calculates the average of positive temperatures, the average of negative temperatures, and counts how many temperatures are zero.

## Files
source files:
- `Temperature_Analyzer.c`
  The main source file. It contains the complete program logic, including reading temperatures, counting positive/negative/zero values, calculating averages, and printing results.


## Compile and Run

```bash
gcc -Wall -Wextra -std=c11 Temperature_Analyzer.c -o temperature
./temperature
```


## Sample Input and Output

sample input :
Enter temperature 1: 10
Enter temperature 2: -5
Enter temperature 3: 0
Enter temperature 4: 20
Enter temperature 5: -10
Enter temperature 6: 1
Enter temperature 7: 1
Enter temperature 8: 1
Enter temperature 9: 1
Enter temperature 10: 11
Enter temperature 11: 1
Enter temperature 12: 1
Enter temperature 13: 1
Enter temperature 14: 1
Enter temperature 15: 1

output :
--- Results ---
Zero count: 1
positive average: 4.17
negative average: -7.50

## What I Learned
This program helped me learn and master the fundamentals of C programming, including the proper use of variables, `for` loops, `scanf()`, `printf()`, and `if/else` statements for data processing.

One challenge was handling cases where there was no data for positive or negative temperatures. Without first checking the counter values, the program could encounter a division-by-zero error when calculating the average.

To resolve this, I added conditional checks before the division operation to verify whether the counts for positive or negative temperatures were greater than zero. If no data exists, the program outputs "none" instead.


