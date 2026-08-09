# BroBank

## Overview

BroBank is a banking system that integrates various data structures and algorithms.

The program utilizes:
- Queue: Stores pending transactions in a First-In-First-Out (FIFO) order.
- Stack: Stores successful transactions to enable undo operations.
- Breadth-First Search (BFS): Finds the shortest transfer path between accounts.
- Depth-First Search (DFS): Checks for the existence of a transfer path.

The program validates deposit, withdrawal, and transfer operations before modifying account balances.

## Key Features

- Submit and process banking transactions using a queue.
- Undo the most recent successful transaction using a stack.
- Search the account transfer graph using BFS and DFS.
- Reject invalid transactions without changing account balances.

## Technical Highlights

This project demonstrates modular C programming using multiple .c and .h files.

The main concepts demonstrated are:
Structures
Pointers
Functions
Queue and Stack data structures
FIFO and LIFO behavior
BFS and DFS graph searching
Transaction validation
Testing and debugging

## Project Structure

- `main.c`  
Contains the test program used to demonstrate the various functions of BroBank.
- `bank.c` 
Implements the core banking functions
- `bank.h`
Defines the BroBank structure, transaction types, and function declarations.
- `sample_input.txt`
sample input document
- `sample_output.txt`
samole output document
- `adt.c`
Implements the Stack and Queue data structures.
- `adt.h`
Contains the definitions for the Stack and Queue.


## Compile and Run

```bash
gcc -Wall -Wextra -std=c11 main.c bank.c adt.c -o bank
./bank
```



## Example
 `sample_input.txt` and `sample_output.txt` were created.
This program uses a built-in test case in `main.c`, 
 `sample_input.txt` need type the number of accounts and initial balance

`sample_output.txt` shows the expected result:
=== Test 1: Deposit and Undo ===
Balance after deposit: 150.00
Balance after undo: 100.00

=== Test 2: Invalid Withdrawal ===
Invalid withdrawal result: 0
Balance after failed withdrawal: 100.00

=== Test 3: BFS Graph Search ===
Shortest transfer distance: 2

=== Test 4: DFS Graph Search ===
Route exists: 1

=== Test 5: Empty Queue ===
Process empty queue result: 0

=== All tests completed ===

## Design and Testing

DESIGN:BroBank uses different data structures to distinguish between various operations.
The pending transaction system uses a queue, as transactions must be processed in a First-In-First-Out (FIFO) order.
The reversal system uses a stack, as the most recent successful transaction should be reversed first.
Before modifying account balances, the program validates transactions to prevent invalid updates.

IPORTANT TEXT CASE:
The following tests were performed using the demonstration program in `main.c`:
1. Deposit and Undo
Expected:
A successful deposit increases the account balance, and undo restores the previous balance.
Actual:
Balance changed from 100.00 to 150.00 and returned to 100.00.
Result:
Passed.
2. Invalid Withdrawal
Expected:
A withdrawal larger than the account balance is rejected and does not change the balance.
Actual:
The transaction returned failure and the balance remained unchanged.
Result:
Passed.

//BUG FIXED

A significant bug fixed during this process involved incorrect status updates following a failed transaction.
The program previously required stricter validation before modifying account balances. Additional validation checks have now been implemented to ensure that failed withdrawals or invalid transactions do not alter the balance or get added to the undo stack.

## Acknowledgments

AI tools : chatgpt
