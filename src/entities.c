#include "entities.h"

#if 1

lights_t lights;

static void ambient_light(float intensity) {
    // TODO
}

static void point_light(float intensity, vec3f_t position) {

}

static void dir_light(float intensity, vec3f_t direction) {

}

void normalize(void) {
    float total_intensity = .0;
    for (int i = 0; i < lights.count; ++i)
        total_intensity += lights.light[i].intensity;
    for (int i = 0; i < lights.count; ++i)
        lights.light[i].intensity /= total_intensity;
    
}

void lights_init(void) {
    lights.count = 0;
    lights.init = lights_init;
    lights.normalize = normalize;
    lights.add.ambient_light = ambient_light;    
    lights.add.dir_light = dir_light;    
    lights.add.point_light = point_light;    
}


#endif
