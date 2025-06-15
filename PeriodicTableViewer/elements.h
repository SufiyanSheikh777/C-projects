// elements.h

#ifndef ELEMENTS_H
#define ELEMENTS_H

struct Element {
    int atomicNumber;
    char name[20];
    char symbol[5];
    float atomicWeight;
    char type[30];
    char block;  // Added block field (s, p, d, f)
};

extern struct Element elements[];
extern int totalElements;

void displayElement(struct Element e);
void viewAll();
void searchByAtomicNumber(int num);
void searchBySymbol(char symbol[]);
void searchByName(char name[]);
void filterByBlock(char block[]);
void filterByType(char type[]);

#endif