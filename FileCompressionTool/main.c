#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codec.h"
#include "codec.c"

int main() {
    int choice;
    char inputFile[100], outputFile[100], password[100];

    while (1) {
        printf("\n\033[1;34m--- File Compression Tool ---\033[0m\n");
        printf("1. Compress File\n");
        printf("2. Decompress File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter input file to compress: ");
                scanf("%s", inputFile);
                printf("Enter output compressed file: ");
                scanf("%s", outputFile);
                printf("Set a password: ");
                scanf("%s", password);
                compressFile(inputFile, outputFile, password);
                break;
            case 2:
                printf("Enter compressed input file: ");
                scanf("%s", inputFile);
                printf("Enter output file after decompression: ");
                scanf("%s", outputFile);
                printf("Enter password: ");
                scanf("%s", password);
                decompressFile(inputFile, outputFile, password);
                break;
            case 3:
                exit(0);
            default:
                printf("\033[1;31mInvalid choice!\033[0m\n");
        }
    }
    return 0;
}
