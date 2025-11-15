#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "mnemonic.h"

#define BUFFER_SIZE 32

uint8_t rand_digits() { return rand() % 100; }

void flush() {
  char ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;
}

uint32_t strip_trailing_newline(char *buffer) {
  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
    return 1;
  }
  return 0;
}

int32_t main() {
  srand(time(NULL));

  char buffer[BUFFER_SIZE];
  const char *reference_word;
  uint8_t rand_number;
  uint32_t score = 0;

  for (;;) {
    rand_number = rand_digits();
    reference_word = mnemonic_get_word(rand_number);

    printf("Current Score: %d | Random digits: %02d\n", score, rand_number);
    printf("Input:");
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
      if (!strip_trailing_newline(buffer)) {
        flush();
      }
    }
    printf("Reference word: %s | You've entered: %s\n\n", reference_word, buffer);
    score = strcmp(buffer, reference_word) ? 0 : score + 1;
  }
  return 0;
}