#include "entities.h"
#include "vmath.h"
#include <stdbool.h>
#include <math.h>

lights_t lights;
camera_t camera;

vec3f_t ray_at(ray_t ray, float t) {
    return (vec3f_t) {ray.origin.x + t*ray.dir.x, ray.origin.y + t*ray.dir.y, ray.origin.z + t*ray.dir.z};
}

vec3f_t ray_intersect(ray_t ray, solid_t* solid, bool* does_intersect) {
    *does_intersect = false;
    vec3f_t ret = {0, 0, 0};
    switch (solid->type) {
        case SOLID_SPHERE:
            float r = solid->sphere.rad;
            vec3f_t CO = vec3f_sub(ray.origin, solid->origin);
            vec3f_t d = ray.dir;
            float a = vec3f_dot(d, d);
            float b = 2 * vec3f_dot(CO, d);
            float c = vec3f_dot(CO, CO) - r*r;
            float discriminant = b*b - 4*a*c;
            if (discriminant < 0)
                return ret;
            float t1 = (-b + sqrt(discriminant)) / (2*a);
            float t2 = (-b - sqrt(discriminant)) / (2*a);
            float t = (t1 > 0 && (t2 <= 0 || t1 < t2)) ? t1 : t2;
            ret = ray_at(ray, t);
            *does_intersect = true;
            break;
        default:
            return ret;
    }
    return ret;
}

void sphere_init(solid_t* solid, float rad) {
    solid->type = SOLID_SPHERE;
    solid->sphere.rad = rad;
}


static void ambient_light(float intensity) {
    lights.light[lights.count++].intensity = intensity;
}

static void point_light(float intensity, float posx, float posy, float posz) {
    lights.light[lights.count].intensity = intensity;
    lights.light[lights.count++].point = (vec3f_t) {posx, posy, posz};
}

static void dir_light(float intensity, float dirx, float diry, float dirz) {
    lights.light[lights.count].intensity = intensity;
    lights.light[lights.count++].dir = (vec3f_t) {dirx, diry, dirz};
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

void camera_init(float cx, float cy, float f, float fovx_deg, float fovy_deg) {
    camera.init = camera_init;
    camera.persp_transform = camera_persp_transform;
    camera.cx = cx;
    camera.cy = cy;
    camera.f = f;
    camera.fovx_deg = fovx_deg;
    camera.fovy_deg = fovy_deg;
}

vec3f_t camera_persp_transform(vec3f_t xyz) {
    const float cx = camera.cx, cy = camera.cy, f = camera.f;
    // to denote it's a 2D vector I set z=0
    return (vec3f_t) {f*xyz.x/xyz.z - cx, f*xyz.y/xyz.z - cy, 0};
}

#if 0
void camera_init(float cx, float cy, float f, float fovx_deg, float fovy_deg) {
    camera.cx = cx;  
    camera.cy = cy;  
    camera.f = f;  
    camera.fovx_deg = fovx_deg;  
    camera.fovy_deg = fovy_deg;  
}
#endif
