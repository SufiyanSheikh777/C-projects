#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"


//function to add contact
void addContact(){
    FILE *fp = fopen("contacts.dat","ab");
    struct Contact c;
    printf("Enter name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter Phone: ");
    scanf(" %[^\n]", c.phone);
    printf("Enter Email: ");
    scanf(" %[^\n]", c.email);
    fwrite(&c, sizeof(c), 1, fp);
    fclose(fp);
    printf("Contact added!\n");
}

//function to display contacts
void displayContacts() {
    FILE *fp = fopen("contacts.dat", "rb");
    struct Contact c;
    while (fread(&c, sizeof(c), 1, fp)) {
        printf("\nName: %s\nPhone: %s\nEmail: %s\n", c.name, c.phone, c.email);
    }
    fclose(fp);
}


//function to search contact
void searchContact() {
    FILE *fp = fopen("contacts.dat", "rb");
    struct Contact c;
    char searchName[50];
    int found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, searchName) == 0) {
            printf("\nFound!\nName: %s\nPhone: %s\nEmail: %s\n", c.name, c.phone, c.email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }

    fclose(fp);
}


//function to delete contact
void deleteContact() {
    FILE *fp = fopen("contacts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Contact c;
    char deleteName[50];
    int deleted = 0;

    printf("Enter name to delete: ");
    scanf(" %[^\n]", deleteName);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, deleteName) != 0) {
            fwrite(&c, sizeof(c), 1, temp);
        } else {
            deleted = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("contacts.dat");
    rename("temp.dat", "contacts.dat");

    if (deleted)
        printf("Contact deleted.\n");
    else
        printf("Contact not found.\n");
}


//function to edit contact
void editContact() {
    FILE *fp = fopen("contacts.dat", "rb+");
    struct Contact c;
    char editName[50];
    int found = 0;

    printf("Enter name to edit: ");
    scanf(" %[^\n]", editName);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, editName) == 0) {
            printf("Enter new name: ");
            scanf(" %[^\n]", c.name);
            printf("Enter new phone: ");
            scanf(" %[^\n]", c.phone);
            printf("Enter new email: ");
            scanf(" %[^\n]", c.email);

            fseek(fp, -sizeof(c), SEEK_CUR);
            fwrite(&c, sizeof(c), 1, fp);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Contact not found.\n");
    else
        printf("Contact updated.\n");

    fclose(fp);
}