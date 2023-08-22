#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib/basicMath/basicMath.h"
#include "lib/stupidMath/stupidMath.h"
#include "lib/cJSON/cJSON.h"

#ifndef CMAKEMACROSAMPLE
    #define CMAKEMACROSAMPLE "NO SYSTEM NAME"
#endif

int main() {
    srand(time(NULL));
    printf("Hello World! You are using a %s\n", CMAKEMACROSAMPLE);
    char test[100] = "{\"Size\": 100}";
    cJSON *json = cJSON_Parse(test);
    if (json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {fprintf(stderr, "Error before: %s\n", error_ptr);}
        goto end; }
    char *string = cJSON_Print(json);
    printf("%s\n", string);
    goto end;
    end:
        cJSON_Delete(json);
        if (string != NULL) {
            free(string);
        }
        return 0;
}