// main.c

#include <stdio.h>
#include "phonebook.h"
#include "phonebook.c"

void menu() {
    printf("\nPhone Book Application\n");
    printf("1. Add Contact\n");
    printf("2. Display All Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Edit Contact\n");
    printf("6. Exit\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: editContact(); break;
            case 6: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
