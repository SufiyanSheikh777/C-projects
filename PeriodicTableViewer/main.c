// main.c

#include <stdio.h>
#include "elements.h"
#include "functions.c"
int main() {
    int choice;
    while (1) {
        printf("\n--- Periodic Table Viewer ---\n");
        printf("1. View All Elements\n");
        printf("2. Search by Atomic Number\n");
        printf("3. Search by Symbol\n");
        printf("4. Search by Name\n");
        printf("5. Filter by Block (s/p/d/f)\n");
        printf("6. Filter by Type (e.g., Alkali Metal, Noble Gas)\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            viewAll();
        } else if (choice == 2) {
            int num;
            printf("Enter Atomic Number: ");
            scanf("%d", &num);
            searchByAtomicNumber(num);
        } else if (choice == 3) {
            char sym[5];
            printf("Enter Symbol: ");
            scanf("%s", sym);
            searchBySymbol(sym);
        } else if (choice == 4) {
            char name[20];
            printf("Enter Name: ");
            scanf("%s", name);
            searchByName(name);
        } else if (choice == 5) {
            char blk[5];
            printf("Enter block (s/p/d/f): ");
            scanf("%s", blk);
            filterByBlock(blk);
        } else if (choice == 6) {
            char t[30];
            printf("Enter type (e.g., Noble Gas): ");
            scanf(" %[^\n]", t);  // Read full line including spaces
            filterByType(t);
        } else if (choice == 7) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
