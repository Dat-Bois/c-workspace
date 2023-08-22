#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "lib/cJSON/cJSON.h"

#ifndef SYSTEMTYPE
    #define SYSTEMTYPE "NO SYSTEM NAME"
#endif

cJSON* parser(char *data) {
    cJSON *json = cJSON_Parse(data);
    if (json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {fprintf(stderr, "Error before: %s\n", error_ptr);}
        return NULL;
        }
    return json;
}

void printJson(cJSON *data, bool clear) {
    if(data == NULL) {
        return;
    }
    char *string = cJSON_Print(data);
    printf("%s\n", string);
    free(string);
    if(clear) {
        cJSON_Delete(data);
    }
}

int main() {
    srand(time(NULL));
    printf("Hello World! You are using a %s\n", SYSTEMTYPE);
    char test[100] = "{\"Size\": 100}";
    printJson(parser(test), true);
    char input[200];
    fgets(input, 200, stdin);
    input[strlen(input)-1] = '\0';
    printJson(parser(input), true);

}