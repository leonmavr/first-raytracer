#include "src/math.h"
//#include "src/entities.h"
#include <stdint.h>
#include <stdio.h>

int main() {
    vec3f_t v1 = {1.0, 0.5}, v2 = {0.001,-2}; 
    float v3 = vec3_angle(v1, v2);
    printf("%f\n", v3);
    printf("%f, %f\n", vec3_add(v1, v2).x, vec3_div(v1, v2).y);
    return 0;
}
