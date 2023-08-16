#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char result[100] = "Hello ";
    char name[50];
    printf("Enter your name: ");
    fgets(name, 50, stdin);
    name[strlen(name)-1] = '\0';
    strcat(result, name);
    strcat(result, ". You seem super cool!\n");
    printf("%s", result);
    return 0;
}