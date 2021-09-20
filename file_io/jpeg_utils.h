#ifndef JPEG_UTILS_H_
#define JPEG_UTILS_H_

#include <stdio.h>
#include <arpa/inet.h>

#define SOI 0xFFD8

typedef struct {
    uint16_t length;
    unsigned char identifier[5];
    uint16_t version;
    unsigned char units;
    uint16_t xdensity;
    uint16_t ydensity;
    unsigned char xthumbnail;
    unsigned char ythumbnail;
} APP0;

typedef struct __attribute__((__packed__)) {
    uint16_t length;
    unsigned char precision;
    uint16_t height;
    uint16_t width;
    unsigned char num_comp;
} SOF;

// Checks if file contains the JPEG signature.
int check_jpeg(FILE*);

// Reads a 16 byte file marker at the current pointer.
uint16_t read_marker(FILE*);

// Reads an APPn marker.
long read_appn(FILE*);

// Reads a Start of Frame marker
long read_sof(FILE*, SOF*);

// Print the APP0 data to shell
void print_appn(APP0);

// Skips to the next marker.
int skip_to_marker(FILE*, uint16_t);

#endif // JPEG_UTILS_H_
