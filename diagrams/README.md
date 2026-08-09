# Diagram or Visualization

![alt text](brobank-module-diagram.png)

## Diagram Explanation
This diagram illustrates the core structure and data flow of the BroBank implementation.
A queue manages pending transactions using the First-In-First-Out (FIFO) principle.
Upon validation, successful transactions update account balances and are pushed onto the undo stack.
The account graph utilizes BFS and DFS to identify transfer relationships between accounts.
This diagram shows the main flow of the BroBank program and how the different parts work together.
This diagram connects directly to the implementation in `main.c`, `bank.c`, `bank.h`, `adt.c`, and `adt.h`.
## Diagram Link

![alt text](brobank-module-diagram.png)
