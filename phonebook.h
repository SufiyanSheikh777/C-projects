#ifndef PHONEBOOK_H
#define PHONEBOOK_H

struct Contact{
    char name[50];
    char phone[15];
    char email[50];
};

void addContact();
void displayContact();
void searchContact();
void deleteContact();
void editContact();

#endif