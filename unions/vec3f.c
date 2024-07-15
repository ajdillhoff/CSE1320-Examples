#include <stdio.h>

typedef union {
    struct {
        float x, y, z;
    };
    float data[3];
} vec3f_t;

struct vec3f_s {
    float x, y, z;
    float data[3];
};

int main() {
    vec3f_t v = { 1.0, 2.0, 3.0 };

    printf("sizeof(v) = %ld\n", sizeof(v));

    v.y = 2.5;

    printf("(");
    for (int i = 0; i < 2; i++) {
        printf("%d, ", v.data[i]);
    }
    printf("%d)\n", v.data[2]);

    printf("(%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);

    return 0;
}
