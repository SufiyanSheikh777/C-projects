// account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    int id;
    char name[50];
    char phone[15];
    double balance;
} Account;

// Function declarations
void create_account();
void view_account(int id);
void list_accounts();
void delete_account(int id);

#endif
