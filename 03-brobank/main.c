#include <stdio.h>
#include "bank.h"

int main(void)
{
    int num_accounts;
    double initial_balance;

    // Prompt user for number of accounts and initial balance
    if (scanf("%d %lf", &num_accounts, &initial_balance) != 2) {
        num_accounts = 3;
        initial_balance = 100.0;
    }

    BroBank bank;
    // Initialize bank using input
    brobank_init(&bank, num_accounts);

    printf("=== Test 1: Deposit and Undo ===\n");
    // Set initial balance
    bank.balances[0] = initial_balance;

    // Create a deposit transaction
    Transaction deposit;
    deposit.type = TX_DEPOSIT;
    deposit.from = -1;
    deposit.to = 0;
    deposit.amount = 50.0;

    // Submit and process the deposit
    brobankSubmit(&bank, deposit);
    brobankProcessNext(&bank);
    printf("Balance after deposit: %.2f\n", bank.balances[0]);

    // Undo the deposit
    brobankUndo(&bank);
    printf("Balance after undo: %.2f\n\n", bank.balances[0]);

    printf("=== Test 2: Invalid Withdrawal ===\n");
    // Create a withdrawal larger than balance
    Transaction withdraw;
    withdraw.type = TX_WITHDRAW;
    withdraw.from = 0;
    withdraw.to = -1;
    withdraw.amount = 500.0;

    brobankSubmit(&bank, withdraw);

    // This should fail because balance is not enough
    int result = brobankProcessNext(&bank);
    printf("Invalid withdrawal result: %d\n", result);
    printf("Balance after failed withdrawal: %.2f\n\n", bank.balances[0]);

    printf("=== Test 3: BFS Graph Search ===\n");
    // Create graph: 0 -> 1 -> 2
    bank.graph[0][1] = 1;
    bank.graph[1][2] = 1;

    int distance = brobankBFS(&bank, 0, 2);
    printf("Shortest transfer distance: %d\n\n", distance);

    printf("=== Test 4: DFS Graph Search ===\n");
    int reachable = brobankDFS(&bank, 0, 2);
    printf("Route exists: %d\n\n", reachable);

    printf("=== Test 5: Empty Queue ===\n");
    int emptyResult = brobankProcessNext(&bank);
    printf("Process empty queue result: %d\n\n", emptyResult);

    printf("=== All tests completed ===\n");
    return 0;
}