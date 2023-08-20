#include <stdio.h>
#include <stdlib.h>

float sum(float x, float y) {
    float solve = x+y;
    printf("%.2f + %.2f = %.2f\n", x, y, solve);
    return solve;
}
float minus(float x, float y) {
    float solve = x-y;
    printf("%.2f - %.2f = %.2f\n", x, y, solve);
    return solve;
}
float multiply(float x, float y) {
    float solve = x*y;
    printf("%.2f * %.2f = %.2f\n", x, y, solve);
    return solve;
}
float divide(float x, float y) {
    float solve = x/y;
    printf("%.2f / %.2f = %.2f\n", x, y, solve);
    return solve;
}