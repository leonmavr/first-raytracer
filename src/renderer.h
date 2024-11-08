#ifndef RENDERER_H
#define RENDERER_H

#include "entities.h" 

void render_solid(solid_t* solid);
vec3i32_t proj2pbuffer(vec3f_t proj);

#endif // RENDERER_H
