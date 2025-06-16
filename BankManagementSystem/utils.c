// utils.c
#include <stdio.h>
#include "account.h"
#include "transaction.h"


#define FILE_NAME "accounts.dat"

void deposit(int id, double amount) {
    FILE *fp = fopen(FILE_NAME, "rb+");
    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.id == id) {
            acc.balance += amount;
            log_transaction(id, "Deposit", amount);
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, fp);
            printf("💰 ₹%.2lf deposited. New balance: ₹%.2lf\n", amount, acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("⚠️ Account not found.\n");
    }

    fclose(fp);
}

void withdraw(int id, double amount) {
    FILE *fp = fopen(FILE_NAME, "rb+");
    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.id == id) {
            if (acc.balance >= amount) {
                acc.balance -= amount;
                log_transaction(id, "Withdraw", amount);
                fseek(fp, -sizeof(Account), SEEK_CUR);
                fwrite(&acc, sizeof(Account), 1, fp);
                printf("💸 ₹%.2lf withdrawn. New balance: ₹%.2lf\n", amount, acc.balance);
            } else {
                printf("❌ Insufficient balance.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("⚠️ Account not found.\n");
    }

    fclose(fp);
}
