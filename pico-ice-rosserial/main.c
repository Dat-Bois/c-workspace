#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "cJSON.h"

#ifndef SYSTEMTYPE
    #define SYSTEMTYPE "NO SYSTEM NAME"
#endif

#ifdef FOUND_PICO_SDK
    #include "pico/stdlib.h"
#endif

void picoLED(int state) {
    #ifdef FOUND_PICO_SDK
        gpio_put(25, state);
    #endif
}

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

void flashError() {
    #ifdef FOUND_PICO_SDK
        for(int i=0; i<5;i++) {
            picoLED(1);
            sleep_ms(80);
            picoLED(0);
            sleep_ms(80);
        }
    #endif
}

void printJson(cJSON *data, bool clear) {
    if(data == NULL) {
        flashError();
        return;
    }
    char *string = cJSON_Print(data);
    printf("%s\n", string);
    free(string);
    if(clear) {
        cJSON_Delete(data);
    }
}

char* getInput() {
    char userInput[2];
    userInput[1] = '\0';
    int brackets = 0;
    char* data = (char*)malloc(200); //sizeof(char) is 1 anyways
;    while(1) {
        userInput[0] = getchar();
        if(userInput[0]=='{') {
            picoLED(1);
            brackets++;
            strcat(data, userInput);
            while(brackets!=0) {
                userInput[0] = getchar();
                if(userInput[0]=='{') {
                    brackets++;
                }
                if(userInput[0]=='}') {
                    brackets--;
                }
                strcat(data, userInput);
            }
            data[strlen(data)] = '\0';
            picoLED(0);
            printf("%s\n", data);
            return data;
        }
    }
}


int main() {
    srand(time(NULL));
    printf("Hello World! You used a %s to compile this code\n", SYSTEMTYPE);
    char test[100] = "{\"Size\": 100}";
    printJson(parser(test), true);
    #ifdef FOUND_PICO_SDK
        stdio_init_all();
        gpio_init(25);
        gpio_set_dir(25, GPIO_OUT);
        picoLED(0);
        while(true) {
            printJson(parser(getInput()), true);
        }
    #endif
    char input[200];
    fgets(input, 200, stdin);
    input[strlen(input)-1] = '\0';
    printJson(parser(input), true);
}