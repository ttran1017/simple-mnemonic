#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "words.h"

#define BUFFER_SIZE 256

uint8_t rand_digits(){
    return rand() % 100;
}

int32_t main()
{
    srand(time(NULL));

    char input[BUFFER_SIZE];
    uint8_t rand_number;
    for(;;){
        rand_number = rand_digits();
        printf("Random digits: %02d\n", rand_number);
        printf("Input:");
        if(fgets(input, BUFFER_SIZE, stdin) == NULL){
            break;
        }
        printf("Word: %s | You've entered: %s\n", mnemonic_words[rand_number], input);

    }
    return 0;
}