#include "ppm_writer.h"
#include "entities.h"
#include <stdint.h>
#include <stdio.h>


#if 0
void generate_gradient(int width, int height) {
    for (int r = 0; r < height; ++r) {
        uint8_t green = (uint8_t)(255 * (1.0 - (float)r / height)); // Green decreases
        uint8_t blue = (uint8_t)(255 * ((float)r / height));        // Blue increases
        for (int c = 0; c < width; ++c) {
            pbuffer_write(c, r, 0, green, blue);
        }
    }
}
#endif

int main() {
    lights_init(); 
    lights.add.ambient_light(2);
    lights.add.dir_light(5, 0.2, 0.1, 0);
    lights.add.point_light(3, 100, 120, 400 );
    lights.normalize();
    printf("%f\n", lights.light[2].intensity);
    //pbuffer_save_ppm("out.ppm");
    //printf("Gradient image saved to %s\n", "out.ppm");
    return 0;
}
