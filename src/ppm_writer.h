#ifndef PPM_WRITER_H
#define PPM_WRITER_H 

#include <stdio.h>  // fprintf
#include <stdint.h> // uint9

#ifndef PBUFFER_HEIGHT
#define PBUFFER_HEIGHT 360
#endif

#ifndef PBUFFER_WIDTH 
#define PBUFFER_WIDTH 480 
#endif

/* pixel buffer */
static uint8_t pbuffer[PBUFFER_HEIGHT][PBUFFER_WIDTH][3];

void pbuffer_write(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    pbuffer[y][x][0] = r;
    pbuffer[y][x][1] = g;
    pbuffer[y][x][2] = b;
}

/**
 * A ppm image file looks as follows:
 *
 * P3
 * # that's a comment
 * # P3 means colours are 8-bit
 * # c = columns, r = rows
 * # m = max colour, e.g. 255
 * c r
 * m
 * # below is the data section with rgb triplets
 * r g b r g b ... r g b
 * .                   .
 * .                   .
 * .                   .
 * r g b r g b ... r g b
 */
void pbuffer_save_ppm(const char* filepath) {
    FILE* fout = fopen(filepath, "wb");
    if (fout == NULL) {
        perror("Error opening output file.\n");
        return;
    }
    fprintf(fout, "P3\n%d %d\n255\n", PBUFFER_WIDTH, PBUFFER_HEIGHT);
    
    for (int r = 0; r < PBUFFER_HEIGHT; ++r) {
        for (int c = 0; c < PBUFFER_WIDTH; ++c) {
            fprintf(fout, "%u %u %u ", pbuffer[r][c][0], pbuffer[r][c][1], pbuffer[r][c][2]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
}


#endif // PPM_WRITER_H
