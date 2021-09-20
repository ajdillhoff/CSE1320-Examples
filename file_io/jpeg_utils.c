#include "jpeg_utils.h"

/*
 * Checks the next 2 bytes to see if it matches the JPEG file signature.
 */
int check_jpeg(FILE *fp) {
    uint16_t buffer = 0;

    fread(&buffer, sizeof(uint16_t), 1, fp);

    return htons(buffer) != SOI;
}

/*
 * Reads the marker at the given file pointer.
 */
uint16_t read_marker(FILE *fp) {
    uint16_t buffer = 0;

    fread(&buffer, sizeof(uint16_t), 1, fp);

    return htons(buffer);
}

/*
 * Reads APPn marker data at the current file pointer.
 */
long read_appn(FILE *fp) {
    APP0 temp;

    fread(&temp, sizeof(temp), 1, fp);

    temp.length = htons(temp.length);
    temp.version = htons(temp.length);
    temp.xdensity = htons(temp.xdensity);
    temp.ydensity = htons(temp.ydensity);

    print_appn(temp);

    // move past thumbnail data
    fseek(fp, temp.length - sizeof(temp), SEEK_CUR);
    return temp.length - sizeof(temp);
}

/*
 * Reads Start of Frame marker data at the current file pointer.
 */
long read_sof(FILE *fp, SOF *temp) {
    fread(temp, sizeof(SOF), 1, fp);

    temp->length = htons(temp->length);
    temp->height = htons(temp->height);
    temp->width = htons(temp->width);

    fseek(fp, temp->length - sizeof(temp), SEEK_CUR);
    return temp->length - sizeof(temp);
}

/*
 * Print APP0 data.
 */
void print_appn(APP0 a) {
    printf("Length: \t%hu\n", a.length);
    printf("Identifier: \t%s\n", a.identifier);
    printf("Version: \t%hhu %hhu\n", a.version > 8, a.version & 0xFF00);
    printf("Density Units: \t%d\n", a.units);
    printf("Xdensity: \t%hu\n", a.xdensity);
    printf("Ydensity: \t%hu\n", a.ydensity);
    printf("Xthumbnail: \t%hhu\n", a.xthumbnail);
    printf("Ythumbnail: \t%hhu\n", a.ythumbnail);
}

/*
 * Print Start of Frame data.
 */
void print_sof(SOF a) {
    printf("Length: \t%hu\n", a.length);
    printf("Precision: \t%hhu\n", a.precision);
    printf("Height: \t%hu\n", a.height);
    printf("Width:  \t%hu\n", a.width);
    printf("NumComp: \t%hhu\n", a.num_comp);
}

/*
 * Searches file until the desired marker is found.
 */
int skip_to_marker(FILE *fp, uint16_t marker) {
    unsigned char byte = 0;
    int found = 0;
    while (!found && !feof(fp)) {
        while ((byte = fgetc(fp)) != 0xFF);

        byte = fgetc(fp);
        if (byte == (marker & 0x00FF)) {
            found = 1;
        }
    }

    return found;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("USAGE: jpeg_utils FILENAME\n");
        return 1;
    }

    printf("sizeof(short) = %ld\n", sizeof(short));

    FILE *fp = fopen(argv[1], "r");

    int result = check_jpeg(fp);

    if (result) {
        printf("File is not a JPEG.\n");
        return 1;
    }

    int found = skip_to_marker(fp, (uint16_t) 0xFFC0);

    if (found) {
        SOF sof = { 0 };
        read_sof(fp, &sof);
        print_sof(sof);
    }

    return 0;
}
