#include "vmath.h"
#include <math.h>

//---------------------------------------------------------------------------//
// function definitions for each type
//---------------------------------------------------------------------------//
VEC_ADD(u8)
VEC_ADD(i32)
VEC_ADD(f)
VEC_SUB(u8)
VEC_SUB(i32)
VEC_SUB(f)
VEC_MUL(u8)
VEC_MUL(i32)
VEC_MUL(f)
VEC_DIV(f)
VEC_DIV(u8)
VEC_DIV(i32)
VEC_DOT(f)
VEC_DOT(u8)
VEC_DOT(i32)
VEC_SCMUL(f)
VEC_SCMUL(u8)
VEC_SCMUL(i32)
VEC_NORMSQ(f)
VEC_NORMSQ(u8)
VEC_NORMSQ(i32)
VEC_NORM(f)
VEC_NORM(u8)
VEC_NORM(i32)
VEC_UNIT(f)
VEC_UNIT(u8)
VEC_UNIT(i32)
VEC_COS(f)
VEC_COS(u8)
VEC_COS(i32)
VEC_ANGLE(f)
VEC_ANGLE(u8)
VEC_ANGLE(i32)


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
