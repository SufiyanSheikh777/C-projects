#ifndef CODEC_H
#define CODEC_H

void compressFile(const char *inputFile, const char *outputFile, const char *password);
void decompressFile(const char *inputFile, const char *outputFile, const char *password);

#endif
