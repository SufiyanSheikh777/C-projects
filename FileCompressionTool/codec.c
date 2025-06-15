#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include "codec.h"

// Utility to get file size
long getFileSize(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1;
}

// Simple encryption/decryption
char encryptChar(char ch, const char *password, int index) {
    return ch; // No encryption
}


// Run-Length Encoding + XOR Encryption
void compressFile(const char *inputFile, const char *outputFile, const char *password) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in) {
        printf("\033[1;31mError: Cannot open input file!\033[0m\n");
        return;
    }
    if (!out) {
        printf("\033[1;31mError: Cannot create output file!\033[0m\n");
        fclose(in);
        return;
    }

    long originalSize = getFileSize(inputFile);

    char ch, prev;
    int count = 1, index = 0;
    prev = fgetc(in);

    while ((ch = fgetc(in)) != EOF) {
        if (ch == prev) {
            count++;
        } else {
            // Encrypt output
            fprintf(out, "%c%d", encryptChar(prev, password, index++), count);
            prev = ch;
            count = 1;
        }
    }
    fprintf(out, "%c%d", encryptChar(prev, password, index++), count);

    fclose(in);
    fclose(out);

    long compressedSize = getFileSize(outputFile);
    float ratio = (1.0 - (float)compressedSize / originalSize) * 100;

    printf("\033[1;32mCompression successful!\033[0m\n");
    printf("Original Size: %ld bytes\n", originalSize);
    printf("Compressed Size: %ld bytes\n", compressedSize);
    printf("Compression Ratio: \033[1;36m%.2f%%\033[0m\n", ratio);
}

// RLE Decompression + XOR Decryption
void decompressFile(const char *inputFile, const char *outputFile, const char *password) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in) {
        printf("\033[1;31mError: Cannot open compressed file!\033[0m\n");
        return;
    }
    if (!out) {
        printf("\033[1;31mError: Cannot create output file!\033[0m\n");
        fclose(in);
        return;
    }

    char ch;
    int count, index = 0;

    while ((ch = fgetc(in)) != EOF) {
        // ch = encryptChar(ch, password, index++);
        fscanf(in, "%d", &count);
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    printf("\033[1;32mDecompression complete!\033[0m\n");
}
