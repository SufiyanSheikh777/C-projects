// transaction.c
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "transaction.h"

#define TXN_FILE "transactions.dat"

void log_transaction(int account_id, const char* type, double amount) {
    FILE *fp = fopen(TXN_FILE, "ab");
    if (!fp) {
        printf("❌ Failed to open transaction file.\n");
        return;
    }

    Transaction txn;
    static int txn_counter = 1;
    txn.txn_id = txn_counter++;
    txn.account_id = account_id;
    strncpy(txn.type, type, sizeof(txn.type));
    txn.amount = amount;

    time_t now = time(NULL);
    strftime(txn.datetime, sizeof(txn.datetime), "%Y-%m-%d %H:%M", localtime(&now));

    fwrite(&txn, sizeof(Transaction), 1, fp);
    fclose(fp);
}

void view_statement(int account_id) {
    FILE *fp = fopen(TXN_FILE, "rb");
    if (!fp) {
        printf("❌ No transactions found.\n");
        return;
    }

    Transaction txn;
    int found = 0;

    printf("\n📄 Account Statement for ID %d:\n", account_id);
    printf("------------------------------------------------------\n");
    printf("ID\tType\t\tAmount\t\tDate\n");
    printf("------------------------------------------------------\n");

    while (fread(&txn, sizeof(Transaction), 1, fp)) {
        if (txn.account_id == account_id) {
            printf("%d\t%s\t\t₹%.2lf\t%s\n", txn.txn_id, txn.type, txn.amount, txn.datetime);
            found = 1;
        }
    }

    if (!found)
        printf("⚠️ No transactions found for this account.\n");

    fclose(fp);
}
