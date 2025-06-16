// main.c
#include <stdio.h>
#include "account.h"
#include "account.c"
#include "utils.h"
#include "utils.c"
#include "transaction.h"
#include "transaction.c"

int main() {
    int choice, id;
    double amount;

    while (1) {
        printf("\n====== Bank Management System ======\n");
        printf("1. Create Account\n2. View Account\n3. List Accounts\n4. Delete Account\n");
        printf("5. Deposit Money\n6. Withdraw Money\n7. View Account Statement\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_account(); break;
            case 2: 
                printf("Enter Account ID: ");
                scanf("%d", &id);
                view_account(id);
                break;
            case 3: list_accounts(); break;
            case 4: 
                printf("Enter Account ID: ");
                scanf("%d", &id);
                delete_account(id);
                break;
            case 5:
                printf("Enter Account ID: ");
                scanf("%d", &id);
                printf("Enter Amount to Deposit: ");
                scanf("%lf", &amount);
                deposit(id, amount);
                break;
            case 6:
                printf("Enter Account ID: ");
                scanf("%d", &id);
                printf("Enter Amount to Withdraw: ");
                scanf("%lf", &amount);
                withdraw(id, amount);
                break;
            case 7:
                printf("Enter Account ID: ");
                scanf("%d", &id);
                view_statement(id);
             break;
            case 0: return 0;
            default: printf("⚠️ Invalid choice. Try again.\n");
        }
    }
}
