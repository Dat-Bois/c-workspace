#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib/basicMath/basicMath.h"
#include "lib/stupidMath/stupidMath.h"

#ifndef CMAKEMACROSAMPLE
    #define CMAKEMACROSAMPLE "NO SYSTEM NAME"
#endif

int main() {
    srand(time(NULL));
    printf("Hello World! You are using a %s\n", CMAKEMACROSAMPLE);
    return 0;
}