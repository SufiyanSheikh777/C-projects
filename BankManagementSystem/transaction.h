// transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

typedef struct {
    int txn_id;
    int account_id;
    char type[10]; // "Deposit" or "Withdraw"
    double amount;
    char datetime[20];
} Transaction;

void log_transaction(int account_id, const char* type, double amount);
void view_statement(int account_id);

#endif
