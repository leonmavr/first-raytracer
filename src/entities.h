#ifndef ENTITIES_H
#define ENTITIES_H

#include "vmath.h"
#include <stdbool.h> 
#include <stddef.h>  // size_t

#define LIGHTS_CAPACITY 50 // Maximum number of lights that can be added

//----------------------------------------------------------------------------//
// Solids                                                                     //
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
typedef enum {
    LIGHT_AMB = 0,  // ambient
    LIGHT_POINT,    // point
    LIGHT_DIR,      // directional
} light_type_t;


/** 
 * Light source model.
 * There are three types of lights:
 * -- ambient - modelled as additive
 *    Has:
 *        - intensity
 * -- positional - all originate from the same point
 *    Has:
 *        - intensity
 *        - position
 * -- directional - all have the same direction
 *    Has:
 *        - intensity
 *        - direction 
 * All intensities must sum to 1 to avoid overexposure.
 *
 * References:
 * https://gabrielgambetta.com/computer-graphics-from-scratch/03-light.html
 */
typedef struct light_t {
    light_type_t type;
    float intensity;     // normalised intensity contribution
    union {
        vec3f_t dir;     // unit vector 
        vec3f_t point;
    };
} light_t;


typedef struct lights_t {
    light_t light[LIGHTS_CAPACITY];  // Fixed-size array of lights
    size_t count;                     // Number of lights currently in the scene
    struct {
        void (*ambient_light)(float intensity);
        void (*point_light)(float intensity, float posx, float poxy, float posz);
        void (*dir_light)(float intensity, float dirx, float diry, float dirz);
    } add;
    void (*init)(void);
    void (*normalize)(void);
} lights_t;


/**
 * Initialize function pointers and count - call this before adding ligfhts.
 */
void lights_init(void);

/**
 * It's a good practice to call this after adding all lights so their
 * intensities add up to 1.
 */
void normalize(void);

extern lights_t lights;


//------------ later ------------------//
typedef struct {
    vec3f_t origin;
    vec3f_t dir;    // direction unit vector
} ray_t;


#endif // ENTITIES_H
