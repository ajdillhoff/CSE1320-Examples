#include <stdio.h>

typedef union {
    struct {
        float x, y, z;
    };
    float data[3];
} vec3f_t;

int main() {
    vec3f_t v = { 1.0, 2.0, 3.0 };

    v.y = 2.5;

    printf("(");
    for (int i = 0; i < 2; i++) {
        printf("%.2f, ", v.data[i]);
    }
    printf("%.2f)\n", v.data[2]);

    return 0;
}
