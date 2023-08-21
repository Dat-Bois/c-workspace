#include <stdio.h>
#include <stdlib.h>

float stupidSum(float x, float y) {
    x = x * (rand()%100 + 1)/50;
    y = y * (rand()%100 + 1)/50;
    float result = x + y;
    printf("%.2f + %.2f = %.2f\n", x, y, result);
    return result;
}