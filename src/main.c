#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "words.h"

#define BUFFER_SIZE 10

uint8_t rand_digits()
{
    return rand() % 100;
}

void flush()
{
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

int32_t main()
{
    srand(time(NULL));

    char buffer[BUFFER_SIZE];
    const char *reference_word;
    uint8_t rand_number;
    uint32_t score = 0;

    for (;;)
    {
        rand_number = rand_digits();
        reference_word = mnemonic_words[rand_number];

        printf("Current Score: %d | Random digits: %02d\n", score, rand_number);
        printf("Input:");
        if (fgets(buffer, BUFFER_SIZE, stdin) != NULL)
        {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n')
            {
                buffer[len - 1] = '\0';
            }
            else
            {
                flush();
            }
        }
        printf("Reference word: %s | You've entered: %s\n", reference_word, buffer);
        score = strcmp(buffer, reference_word) ? 0 : score + 1;
    }
    return 0;
}