#include "renderer.h"
#include "ppm_writer.h"
#include "utils.h"

void render_solid(solid_t* solid) {
    // TODO: later, do multiple solids of different types
    if (solid->type == SOLID_SPHERE) {

    }
}

vec3i32_t proj2pbuffer(vec3f_t proj) {
    // before calling this, make sure `proj` is visible or we'll end up out of bounds
    // linearly interpolate from the camera screen to pixel buffer
    int px = (int)lerp(0, PBUFFER_WIDTH - 1,
                             (proj.x - camera.boundary.x0) / (camera.boundary.x1 - camera.boundary.x0));
    int py = (int)lerp(0, PBUFFER_HEIGHT - 1,
                             (proj.y - camera.boundary.y0) / (camera.boundary.y1 - camera.boundary.y0));
    return (vec3i32_t) {px, py, 0};
}
