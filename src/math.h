#ifndef __MATH_H__
#define __MATH_H__

#include <stdint.h>
#include <math.h>


typedef unsigned char u8_t;
typedef int32_t i32_t;
typedef float f_t;
typedef struct { u8_t x, y, z; } vec3u8_t;
typedef struct { i32_t x, y, z; } vec3i32_t;
typedef struct { float x, y, z; } vec3f_t;

//---------------------------------------------------------------------------//
// type-agnostic implementations
//---------------------------------------------------------------------------//
#define VEC_ADD(type)                                              \
    vec3##type##_t vec3##type##_add(vec3##type##_t v1,             \
                                    vec3##type##_t v2) {           \
        return (vec3##type##_t) {v1.x+v2.x, v1.y+v2.y, v1.z+v2.z}; \
    }

#define VEC_SUB(type)                                              \
    vec3##type##_t vec3##type##_sub(vec3##type##_t v1,             \
                                    vec3##type##_t v2) {           \
        return (vec3##type##_t) {v1.x-v2.x, v1.y-v2.y, v1.z-v2.z}; \
    }

#define VEC_MUL(type)                                              \
    vec3##type##_t vec3##type##_mul(vec3##type##_t v1,             \
                                    vec3##type##_t v2) {           \
        return (vec3##type##_t) {v1.x*v2.x, v1.y*v2.y, v1.z*v2.z}; \
    }

#define VEC_DIV(type)                                              \
    vec3##type##_t vec3##type##_div(vec3##type##_t v1,             \
                                    vec3##type##_t v2) {           \
        return (vec3##type##_t) {v1.x/v2.x, v1.y/v2.y, v1.z/v2.z}; \
    }

#define VEC_DOT(type)                                              \
    float vec3##type##_dot(vec3##type##_t v1,                      \
                           vec3##type##_t v2) {                    \
        return (float)(v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);         \
    }

#define VEC_SCMUL(type)                                            \
    vec3f_t vec3##type##_scmul(vec3##type##_t v1,                  \
                               float t) {                          \
        return (vec3f_t) {v1.x*t, v1.y*t, v1.z*t};                 \
    }

#define VEC_NORMSQ(type)                                           \
    float vec3##type##_normsq(vec3##type##_t v1) {                 \
        return v1.x*v1.x + v1.y*v1.y + v1.z*v1.z;                  \
    }

#define VEC_NORM(type)                                             \
    float vec3##type##_norm(vec3##type##_t v1) {                   \
        return sqrt(v1.x*v1.x + v1.y*v1.y + v1.z*v1.z);            \
    }

#define VEC_UNIT(type)                                             \
    vec3f_t vec3##type##_unit(vec3##type##_t v1) {                 \
        const float n = vec3##type##_norm(v1);                     \
        return (vec3f_t) {v1.x/n, v1.y/n, v1.z/n};                 \
    }

#define VEC_COS(type) \
    float vec3##type##_cos(vec3##type##_t v1, vec3##type##_t v2) { \
        const float n1 = vec3##type##_norm(v1);                    \
        const float n2 = vec3##type##_norm(v2);                    \
        return vec3##type##_dot(v1, v2)/(n1*n2);                   \
    }

#define VEC_ANGLE(type) \
    float vec3##type##_angle(vec3##type##_t v1, vec3##type##_t v2) { \
        return acos(vec3##type##_cos(v1, v2));                        \
    }


//---------------------------------------------------------------------------//
// macros for generic interface
//---------------------------------------------------------------------------//
#define vec3_add(v1, v2) _Generic((v1),                              \
    vec3u8_t: vec3u8_add,                                            \
    vec3i32_t: vec3i32_add,                                          \
    vec3f_t: vec3f_add)(v1, v2)

#define vec3_sub(v1, v2) _Generic((v1),                              \
    vec3u8_t: vec3u8_sub,                                            \
    vec3i32_t: vec3i32_sub,                                          \
    vec3f_t: vec3f_sub)(v1, v2)

#define vec3_mul(v1, v2) _Generic((v1),                              \
    vec3u8_t: vec3u8_mul,                                            \
    vec3i32_t: vec3i32_mul,                                          \
    vec3f_t: vec3f_mul)(v1, v2)

#define vec3_div(v1, v2) _Generic((v1),                              \
    vec3u8_t: vec3u8_div,                                            \
    vec3i32_t: vec3i32_div,                                          \
    vec3f_t: vec3f_div)(v1, v2)

#define vec3_dot(v1, v2) _Generic((v1),                              \
    vec3u8_t: vec3u8_dot,                                            \
    vec3i32_t: vec3i32_dot,                                          \
    vec3f_t: vec3f_dot)(v1, v2)

#define vec3_scmul(v1, t) _Generic((v1),                             \
    vec3u8_t: vec3u8_scmul,                                          \
    vec3i32_t: vec3i32_scmul,                                        \
    vec3f_t: vec3f_scmul)(v1, t)

#define vec3_normsq(v1) _Generic((v1),                               \
    vec3u8_t: vec3u8_normsq,                                         \
    vec3i32_t: vec3i32_normsq,                                       \
    vec3f_t: vec3f_normsq)(v1)

#define vec3_norm(v1) _Generic((v1),                                 \
    vec3u8_t: vec3u8_norm,                                           \
    vec3i32_t: vec3i32_norm,                                         \
    vec3f_t: vec3f_norm)(v1)

#define vec3_unit(v1) _Generic((v1),                                 \
    vec3u8_t: vec3u8_unit,                                           \
    vec3i32_t: vec3i32_unit,                                         \
    vec3f_t: vec3f_unit)(v1)

#define vec3_cos(v1, v2) _Generic((v1),                              \
    vec3u8_t: vec3u8_cos,                                            \
    vec3i32_t: vec3i32_cos,                                          \
    vec3f_t: vec3f_cos)(v1, v2)

#define vec3_angle(v1, v2) _Generic((v1),                            \
    vec3u8_t: vec3u8_angle,                                          \
    vec3i32_t: vec3i32_angle,                                        \
    vec3f_t: vec3f_angle)(v1, v2)




#endif // _MATH_H 
