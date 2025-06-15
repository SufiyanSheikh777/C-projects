// elements.c

#include <stdio.h>
#include <string.h>
#include "elements.h"
#define MAX_ELEMENTS 118

struct Element elements[MAX_ELEMENTS] = {
     {1, "Hydrogen", "H", 1.008, "Non-metal", 's'},
    {2, "Helium", "He", 4.0026, "Noble Gas", 's'},
    {3, "Lithium", "Li", 6.94, "Alkali Metal", 's'},
    {4, "Beryllium", "Be", 9.0122, "Alkaline Earth Metal", 's'},
    {5, "Boron", "B", 10.81, "Metalloid", 'p'},
    {6, "Carbon", "C", 12.011, "Non-metal", 'p'},
    {7, "Nitrogen", "N", 14.007, "Non-metal", 'p'},
    {8, "Oxygen", "O", 15.999, "Non-metal", 'p'},
    {9, "Fluorine", "F", 18.998, "Halogen", 'p'},
    {10, "Neon", "Ne", 20.180, "Noble Gas", 'p'},
    {11, "Sodium", "Na", 22.990, "Alkali Metal", 's'},
    {12, "Magnesium", "Mg", 24.305, "Alkaline Earth Metal", 's'},
    {13, "Aluminium", "Al", 26.982, "Post-transition Metal", 'p'},
    {14, "Silicon", "Si", 28.085, "Metalloid", 'p'},
    {15, "Phosphorus", "P", 30.974, "Non-metal", 'p'},
    {16, "Sulfur", "S", 32.06, "Non-metal", 'p'},
    {17, "Chlorine", "Cl", 35.45, "Halogen", 'p'},
    {18, "Argon", "Ar", 39.948, "Noble Gas", 'p'},
    {19, "Potassium", "K", 39.098, "Alkali Metal", 's'},
    {20, "Calcium", "Ca", 40.078, "Alkaline Earth Metal", 's'},
    {21, "Scandium", "Sc", 44.956, "Transition Metal", 'd'},
    {22, "Titanium", "Ti", 47.867, "Transition Metal", 'd'},
    {23, "Vanadium", "V", 50.942, "Transition Metal", 'd'},
    {24, "Chromium", "Cr", 51.996, "Transition Metal", 'd'},
    {25, "Manganese", "Mn", 54.938, "Transition Metal", 'd'},
    {26, "Iron", "Fe", 55.845, "Transition Metal", 'd'},
    {27, "Cobalt", "Co", 58.933, "Transition Metal", 'd'},
    {28, "Nickel", "Ni", 58.693, "Transition Metal", 'd'},
    {29, "Copper", "Cu", 63.546, "Transition Metal", 'd'},
    {30, "Zinc", "Zn", 65.38, "Transition Metal", 'd'},
    {31, "Gallium", "Ga", 69.723, "Post-transition Metal", 'p'},
    {32, "Germanium", "Ge", 72.630, "Metalloid", 'p'},
    {33, "Arsenic", "As", 74.922, "Metalloid", 'p'},
    {34, "Selenium", "Se", 78.971, "Non-metal", 'p'},
    {35, "Bromine", "Br", 79.904, "Halogen", 'p'},
    {36, "Krypton", "Kr", 83.798, "Noble Gas", 'p'},
    {37, "Rubidium", "Rb", 85.468, "Alkali Metal", 's'},
    {38, "Strontium", "Sr", 87.62, "Alkaline Earth Metal", 's'},
    {39, "Yttrium", "Y", 88.906, "Transition Metal", 'd'},
    {40, "Zirconium", "Zr", 91.224, "Transition Metal", 'd'},
    {41, "Niobium", "Nb", 92.906, "Transition Metal", 'd'},
    {42, "Molybdenum", "Mo", 95.95, "Transition Metal", 'd'},
    {43, "Technetium", "Tc", 98.0, "Transition Metal", 'd'},
    {44, "Ruthenium", "Ru", 101.07, "Transition Metal", 'd'},
    {45, "Rhodium", "Rh", 102.91, "Transition Metal", 'd'},
    {46, "Palladium", "Pd", 106.42, "Transition Metal", 'd'},
    {47, "Silver", "Ag", 107.87, "Transition Metal", 'd'},
    {48, "Cadmium", "Cd", 112.41, "Transition Metal", 'd'},
    {49, "Indium", "In", 114.82, "Post-transition Metal", 'p'},
    {50, "Tin", "Sn", 118.71, "Post-transition Metal", 'p'},
    {51, "Antimony", "Sb", 121.76, "Metalloid", 'p'},
    {52, "Tellurium", "Te", 127.60, "Metalloid", 'p'},
    {53, "Iodine", "I", 126.90, "Halogen", 'p'},
    {54, "Xenon", "Xe", 131.29, "Noble Gas", 'p'},
    {55, "Cesium", "Cs", 132.91, "Alkali Metal", 's'},
    {56, "Barium", "Ba", 137.33, "Alkaline Earth Metal", 's'},
    {57, "Lanthanum", "La", 138.91, "Lanthanide", 'd'},
    {58, "Cerium", "Ce", 140.12, "Lanthanide", 'f'},
    {59, "Praseodymium", "Pr", 140.91, "Lanthanide", 'f'},
    {60, "Neodymium", "Nd", 144.24, "Lanthanide", 'f'},
    {61, "Promethium", "Pm", 145.0, "Lanthanide", 'f'},
    {62, "Samarium", "Sm", 150.36, "Lanthanide", 'f'},
    {63, "Europium", "Eu", 151.96, "Lanthanide", 'f'},
    {64, "Gadolinium", "Gd", 157.25, "Lanthanide", 'f'},
    {65, "Terbium", "Tb", 158.93, "Lanthanide", 'f'},
    {66, "Dysprosium", "Dy", 162.50, "Lanthanide", 'f'},
    {67, "Holmium", "Ho", 164.93, "Lanthanide", 'f'},
    {68, "Erbium", "Er", 167.26, "Lanthanide", 'f'},
    {69, "Thulium", "Tm", 168.93, "Lanthanide", 'f'},
    {70, "Ytterbium", "Yb", 173.05, "Lanthanide", 'f'},
    {71, "Lutetium", "Lu", 174.97, "Lanthanide", 'd'},
    {72, "Hafnium", "Hf", 178.49, "Transition Metal", 'd'},
    {73, "Tantalum", "Ta", 180.95, "Transition Metal", 'd'},
    {74, "Tungsten", "W", 183.84, "Transition Metal", 'd'},
    {75, "Rhenium", "Re", 186.21, "Transition Metal", 'd'},
    {76, "Osmium", "Os", 190.23, "Transition Metal", 'd'},
    {77, "Iridium", "Ir", 192.22, "Transition Metal", 'd'},
    {78, "Platinum", "Pt", 195.08, "Transition Metal", 'd'},
    {79, "Gold", "Au", 196.97, "Transition Metal", 'd'},
    {80, "Mercury", "Hg", 200.59, "Transition Metal", 'd'},
    {81, "Thallium", "Tl", 204.38, "Post-transition Metal", 'p'},
    {82, "Lead", "Pb", 207.2, "Post-transition Metal", 'p'},
    {83, "Bismuth", "Bi", 208.98, "Post-transition Metal", 'p'},
    {84, "Polonium", "Po", 209.0, "Metalloid", 'p'},
    {85, "Astatine", "At", 210.0, "Halogen", 'p'},
    {86, "Radon", "Rn", 222.0, "Noble Gas", 'p'},
    {87, "Francium", "Fr", 223.0, "Alkali Metal", 's'},
    {88, "Radium", "Ra", 226.0, "Alkaline Earth Metal", 's'},
    {89, "Actinium", "Ac", 227.0, "Actinide", 'd'},
    {90, "Thorium", "Th", 232.04, "Actinide", 'f'},
    {91, "Protactinium", "Pa", 231.04, "Actinide", 'f'},
    {92, "Uranium", "U", 238.03, "Actinide", 'f'},
    {93, "Neptunium", "Np", 237.0, "Actinide", 'f'},
    {94, "Plutonium", "Pu", 244.0, "Actinide", 'f'},
    {95, "Americium", "Am", 243.0, "Actinide", 'f'},
    {96, "Curium", "Cm", 247.0, "Actinide", 'f'},
    {97, "Berkelium", "Bk", 247.0, "Actinide", 'f'},
    {98, "Californium", "Cf", 251.0, "Actinide", 'f'},
    {99, "Einsteinium", "Es", 252.0, "Actinide", 'f'},
    {100, "Fermium", "Fm", 257.0, "Actinide", 'f'},
    {101, "Mendelevium", "Md", 258.0, "Actinide", 'f'},
    {102, "Nobelium", "No", 259.0, "Actinide", 'f'},
    {103, "Lawrencium", "Lr", 262.0, "Actinide", 'd'},
    {104, "Rutherfordium", "Rf", 267.0, "Transition Metal", 'd'},
    {105, "Dubnium", "Db", 270.0, "Transition Metal", 'd'},
    {106, "Seaborgium", "Sg", 271.0, "Transition Metal", 'd'},
    {107, "Bohrium", "Bh", 270.0, "Transition Metal", 'd'},
    {108, "Hassium", "Hs", 277.0, "Transition Metal", 'd'},
    {109, "Meitnerium", "Mt", 278.0, "Unknown", 'd'},
    {110, "Darmstadtium", "Ds", 281.0, "Unknown", 'd'},
    {111, "Roentgenium", "Rg", 282.0, "Unknown", 'd'},
    {112, "Copernicium", "Cn", 285.0, "Transition Metal", 'd'},
    {113, "Nihonium", "Nh", 286.0, "Unknown", 'p'},
    {114, "Flerovium", "Fl", 289.0, "Post-transition Metal", 'p'},
    {115, "Moscovium", "Mc", 290.0, "Unknown", 'p'},
    {116, "Livermorium", "Lv", 293.0, "Post-transition Metal", 'p'},
    {117, "Tennessine", "Ts", 294.0, "Halogen", 'p'},
    {118, "Oganesson", "Og", 294.0, "Noble Gas", 'p'}
};


int totalElements = sizeof(elements) / sizeof(elements[0]);

void displayElement(struct Element e) {
    printf("\n--- Element Info ---\n");
    printf("Atomic Number : %d\n", e.atomicNumber);
    printf("Name          : %s\n", e.name);
    printf("Symbol        : %s\n", e.symbol);
    printf("Atomic Weight : %.3f\n", e.atomicWeight);
    printf("Type          : %s\n", e.type);
    printf("----------------------\n");
}

void viewAll() {
    for (int i = 0; i < totalElements; i++) {
        printf("%d. %s (%s)\n", elements[i].atomicNumber, elements[i].name, elements[i].symbol);
    }
}

void searchByAtomicNumber(int num) {
    for (int i = 0; i < totalElements; i++) {
        if (elements[i].atomicNumber == num) {
            displayElement(elements[i]);
            return;
        }
    }
    printf("Element not found.\n");
}

void searchBySymbol(char symbol[]) {
    for (int i = 0; i < totalElements; i++) {
        if (strcasecmp(elements[i].symbol, symbol) == 0) {
            displayElement(elements[i]);
            return;
        }
    }
    printf("Element not found.\n");
}

void searchByName(char name[]) {
    for (int i = 0; i < totalElements; i++) {
        if (strcasecmp(elements[i].name, name) == 0) {
            displayElement(elements[i]);
            return;
        }
    }
    printf("Element not found.\n");
}

void filterByBlock(char block[]) {
    int found = 0;
    char userBlock = tolower(block[0]);  // convert first char to lowercase for comparison
    printf("\n--- Elements in Block '%c' ---\n", userBlock);
    for (int i = 0; i < totalElements; i++) {
        if (tolower(elements[i].block) == userBlock) {
            printf("%d. %s (%s)\n", elements[i].atomicNumber, elements[i].name, elements[i].symbol);
            found = 1;
        }
    }
    if (!found) {
        printf("No elements found in block '%c'.\n", userBlock);
    }
}

void filterByType(char type[]) {
    int found = 0;
    printf("\n--- Elements of Type '%s' ---\n", type);
    for (int i = 0; i < totalElements; i++) {
        if (strcasecmp(elements[i].type, type) == 0) {
            printf("%d. %s (%s)\n", elements[i].atomicNumber, elements[i].name, elements[i].symbol);
            found = 1;
        }
    }
    if (!found) {
        printf("No elements found of type '%s'.\n", type);
    }
}