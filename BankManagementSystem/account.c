// account.c
#include <stdio.h>
#include <string.h>
#include "account.h"

#define FILE_NAME "accounts.dat"

void create_account() {
    FILE *fp = fopen(FILE_NAME, "ab");
    Account acc;
    
    printf("Enter Account ID: ");
    scanf("%d", &acc.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", acc.name);
    printf("Enter Phone: ");
    scanf(" %s", acc.phone);
    printf("Enter Initial Balance: ");
    scanf("%lf", &acc.balance);

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);
    printf("✅ Account created successfully.\n");
}

void view_account(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.id == id) {
            printf("\n🔍 Account Details:\n");
            printf("ID: %d\nName: %s\nPhone: %s\nBalance: ₹%.2lf\n", acc.id, acc.name, acc.phone, acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("⚠️ Account not found.\n");
    }

    fclose(fp);
}

void list_accounts() {
    FILE *fp = fopen(FILE_NAME, "rb");
    Account acc;
    printf("\n📄 All Accounts:\n");
    printf("----------------------------------------\n");
    while (fread(&acc, sizeof(Account), 1, fp)) {
        printf("ID: %d | Name: %s | Balance: ₹%.2lf\n", acc.id, acc.name, acc.balance);
    }
    fclose(fp);
}

void delete_account(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    Account acc;
    int found = 0;

    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.id == id) {
            found = 1;
            continue;  // Skip the account to be deleted
        }
        fwrite(&acc, sizeof(Account), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("✅ Account deleted successfully.\n");
    else
        printf("⚠️ Account not found.\n");
}
