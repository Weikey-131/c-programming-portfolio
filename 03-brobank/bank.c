#include <string.h>
#include "bank.h"
void brobank_init(BroBank *bank, int account_count) {
    if (!bank){ return; }
    memset(bank, 0, sizeof *bank);
     bank->account_count = account_count;
      bank->p_rear = -1; 
      bank->undo_top = -1;
}
int brobankSubmit(BroBank *bank, Transaction tx) { 
    /* TODO: validate and enqueue transaction. */ 
  // Check pointer if is null
    if (bank == NULL)
    {
        return 0;
    }
 // Reject invalid amounts
    if (tx.amount <= 0)
    {
        return 0;
    }
 // Check if queue is full
    if (bank->p_count == CAPACITY)
    {
        return 0;
    }

// Move rear forward
    bank->p_rear = (bank->p_rear + 1) % CAPACITY;

// Save transaction
    bank->pending[bank->p_rear] = tx;

// Increase queue size
    bank->p_count++;

    return 1;
 }
int brobankProcessNext(BroBank *bank) { 
    /* TODO: dequeue, validate, update balances, push successful undo. */ 
    Transaction tx;
//check pointer if is null
    if (bank == NULL)
    {
        return 0;
    }

// Queue empty
    if (bank->p_count == 0)
    {
        return 0;
    }

 // Read first transaction
    tx = bank->pending[bank->p_front];
// Move front
    bank->p_front = (bank->p_front + 1) % CAPACITY;
// One less transaction
    bank->p_count--;
// Deposit
    if (tx.type == TX_DEPOSIT)
    {
        bank->balances[tx.to] += tx.amount;
    }
// Withdraw
    else if (tx.type == TX_WITHDRAW)
    {
        if (bank->balances[tx.from] < tx.amount)
        {
            return 0;
        }

        bank->balances[tx.from] -= tx.amount;
    }
// Transfer
    else if (tx.type == TX_TRANSFER)
    {
        if (bank->balances[tx.from] < tx.amount)
        {
            return 0;
        }

        bank->balances[tx.from] -= tx.amount;
        bank->balances[tx.to] += tx.amount;
    }
// Save to undo 
    bank->undo_top++;
    bank->undo[bank->undo_top] = tx;

    return 1;
}
int brobankUndo(BroBank *bank) {
     /* TODO: reverse most recent successful transaction. */
    Transaction tx;
//check pointer if is null
    if (bank == NULL)
    {
        return 0;
    }
// Nothing to undo
    if (bank->undo_top < 0)
    {
        return 0;
    }
// Get latest transaction
    tx = bank->undo[bank->undo_top];
// Remove from undo
    bank->undo_top--;
// Reverse deposit
    if (tx.type == TX_DEPOSIT)
    {
        bank->balances[tx.to] -= tx.amount;
    }
// Reverse withdraw
    else if (tx.type == TX_WITHDRAW)
    {
        bank->balances[tx.from] += tx.amount;
    }
 // Reverse transfer
    else if (tx.type == TX_TRANSFER)
    {
        bank->balances[tx.from] += tx.amount;
        bank->balances[tx.to] -= tx.amount;
    }

    return 1;
     }
int brobankBFS(const BroBank *bank, int source, int destination) { 
    /* TODO: fewest transfer edges. */ 
    // Record which accounts have been visited and the distance from the source
    int visited[BROBANK_MAX_ACCOUNTS] = {0};
    int distance[BROBANK_MAX_ACCOUNTS] = {0};
    Queue q; // Create a queue
    int current;  // Store the current account
    // Check if the bank pointer is valid
    if (bank == NULL)
    {
        return -1;
    }
    // Initialize the queue
    queueInit(&q);
    // Put the starting account into the queue
    enqueue(&q, source);
    // Mark the starting account as visited
    visited[source] = 1;
    // Continue while the queue is not empty
    while (!queueIsEmpty(&q))
    {
        // Get the first account in the queue
        dequeue(&q, &current);
        if (current == destination)//if destination found
        {
            return distance[current];
            }
        for (int i = 0; i < bank->account_count; i++)
        {
            // If there is a connection and it has not been visited
            if (bank->graph[current][i] && !visited[i])
            {
                // Mark it before adding it to the queue
                visited[i] = 1;
                distance[i] = distance[current] + 1;
                // Add it to the back of the queue
                enqueue(&q, i);
            }
        }
    }
    // No path found
    return -1;
}
int brobankDFS(const BroBank *bank, int source, int destination) {
     /* TODO: reachability. */ 
      // Record which accounts have been visited
    int visited[BROBANK_MAX_ACCOUNTS] = {0};
    // Create a stack
    Stack s;
    // Store the current account
    int current;
    // Check if the bank pointer is valid
    if (bank == NULL)
    {
        return 0;
    }
    // Initialize the stack
    stackInit(&s);
    // Push the starting account
    stackPush(&s, source);
    // Continue while the stack is not empty
    while (!stackIsEmpty(&s))
    {
        // Get the top account
        stackPop(&s, &current);
        // Skip if already visited
        if (visited[current])
        {
            continue;
        }
        // Mark the account as visited
        visited[current] = 1;
        //if destination found
        if (current == destination)
        {
            return 1;
        }
        for (int i = 0; i < bank->account_count; i++)
        {
            // If there is a connection and it has not been visited
            if (bank->graph[current][i] && !visited[i])
            {
                stackPush(&s, i);// Push it onto the stack
            }
        }
    }
    // No path found
    return 0;
    }
