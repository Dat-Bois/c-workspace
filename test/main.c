#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // char result[100] = "Hello ";
    // char name[50];
    // printf("Enter your name: ");
    // fgets(name, 50, stdin);
    // name[strlen(name)-1] = '\0';
    // strcat(result, name);
    // strcat(result, ". You seem super cool!\n");
    // printf("%s", result);

    // //p2
    // int width;
    // int length;
    // printf("Enter a number for the width: ");
    // scanf("%d", &width);
    // printf("Enter a number for the length: ");
    // scanf("%d", &length);
    // int* array = (int*)malloc(width * length * sizeof(int));
    // if (array == NULL) {
    //     printf("Memory not allocated.\n");
    //     exit(0);
    // }
    // int count = 0;
    // for(int row = 0;row<width;row++) {
    //     for(int col=0;col<length;col++) {
    //         array[row * width + col] = count;
    //         printf("%d ", array[row * width + col]);
    //         count++;
    //     }
    //     printf("\n");
    // }

    // free(array);

    //p3
    int a=10;
    int* ap = &a;
    printf("%d", *ap);
    int* temp = (int*)malloc(sizeof(int));
    //scanf("%d", temp);
    *temp = 20;
    printf("%d", *temp);
    free(temp);

    //p4 pointers
    // int  var[] = {10, 100, 200};
    // int  i, *ptr;

    // /* let us have array address in pointer */
    // ptr = var;
    // const int MAX = 3;
    // for ( i = 0; i < MAX; i++) {

    //     printf("Address of var[%d] = %x\n", i, ptr );
    //     printf("Value of var[%d] = %d\n", i, *ptr );

    //     /* move to the next location */
    //     ptr++;
    // }


    return 0;
}