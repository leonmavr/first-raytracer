#include "src/math.h"
#include "src/ppm_writer.h"
#include "src/entities.h"
//#include "src/entities.h"
#include <stdint.h>
#include <stdio.h>


// Function to generate a green to blue vertical gradient
void generate_gradient(int width, int height) {
    for (int r = 0; r < height; ++r) {
        uint8_t green = (uint8_t)(255 * (1.0 - (float)r / height)); // Green decreases
        uint8_t blue = (uint8_t)(255 * ((float)r / height));        // Blue increases
        for (int c = 0; c < width; ++c) {
            pbuffer_write(c, r, 0, green, blue);
        }
    }
}

int main() {

    generate_gradient(PBUFFER_WIDTH, PBUFFER_HEIGHT);
    pbuffer_save_ppm("out.ppm");

    printf("Gradient image saved to %s\n", "out.ppm");
    return 0;
}
