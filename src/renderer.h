#ifndef RENDERER_H
#define RENDERER_H

#include "entities.h" 
#include "ppm_writer.h"

void render_solid(solid_t* solid) {
    if (solid->type == SOLID_SPHERE) {

    }
    // TODO: implement remaining solids
}

void proj2pbuffer(vec3f_t proj);

// TODO: map projection to pbuffer

#endif // RENDERER_H
