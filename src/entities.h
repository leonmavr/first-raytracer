#ifndef ENTITIES_H
#define ENTITIES_H

#include "math.h"
#include <stdbool.h> 

//----------------------------------------------------------------------------//
// Solids                                                                    //
//----------------------------------------------------------------------------//
typedef enum {
    SOLID_SPHERE = 0,
    SOLID_CHECKERBOARD,
    SOLID_CUBE,
    SOLID_CYLINDER
} solid_type_t;

typedef struct {
    float rad;
} sphere_t;

typedef struct {
    float width;
    float height;
    // size of each square as a fraction of the width and height
    float square_size_norm;
} checkerboard_t;

typedef struct {
    float size;
} cube_t;

typedef struct {
    float rad;          // Radius of the cylinder base
    float height;       // Height of the cylinder
} cylinder_t;

// Generic solid structure that can represent any solid 
typedef struct {
    solid_type_t type;   // identifies the type of solid
    vec3f_t origin;
    float diffusion;
    float reflection;
    float transparency;
    float refraction;
    vec3u8_t color; 
    // it can contain information about one of the following solids 
    union {
        sphere_t sphere;
        checkerboard_t checkerboard;
        cube_t cube;
        cylinder_t cylinder;
    } geometry;
} solid_t;

void sphere_init(sphere_t* sph, solid_t attr, vec3f_t origin, float rad);
void checkerboard_init(checkerboard_t* chboard, solid_t attr, float width,
    float height, float square_size_norm);
void cube_init(cube_t* cube, solid_t attr, float size);
void cylinder_init(cylinder_t* cylinder, solid_t attr, float rad, float height);


//----------------------------------------------------------------------------//
// Rendering                                                                  //
//----------------------------------------------------------------------------//


typedef struct {
    vec3f_t origin;
    vec3f_t dir;
} ray_t;

typedef enum {
    LIGHT_AMB = 0, // ambient
    LIGHT_POINT,   // point
    LIGHT_DIR,     // directional
} light_type_t;

/** 
 * Light source model.
 * Each light source can have the following properties:
 * - type: identifier
 *     ambient/point/directional
 * - intensity: float
 *     0 to 1
 * - position: vec3  (only if type is point)
 * - direction: vec3  (only if type is directional)
 *
 * References:
 *   https://gabrielgambetta.com/computer-graphics-from-scratch/03-light.html
 */
typedef struct light_t {
    light_type_t type;
    float intensity; // intensity contribution
    union {
        vec3i32_t dir; // direction in (3D) scene
        vec3i32_t point; // point line (3D)
    } geometry;
} light_t;

/**
 * Collection of light sources. 
 */
typedef struct lights_t {
    // lights (ambient/directional/point) light sources
    light_t** lights;
    // number of lights
    size_t n;
} lights_t;

typedef struct camera_t {
    float cx;       // center x
    float cy;       // center y
    float f;        // focal length (in pixels)
    float fovx_rad; // field of view along x axis (in rads)
    float fovy_rad; // field of view along y ayis (in rads)
} camera_t;

static camera_t camera;

ray_t ray_make(vec3f_t origin, vec3f_t point);
vec3f_t ray_at(ray_t ray_t, float t);
void ray_intersect(ray_t* ray, solid_t* solid, vec3f_t intersection, bool has_inters);
void camera_set(float cx, float cy, float f, float fov_deg);

#endif // ENTITIES_H
