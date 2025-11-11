#ifndef MNEMONIC_TABLE_H
#define MNEMONIC_TABLE_H

#include <stdint.h>

#define MAX_WORD_COUNT 100

extern const char* mnemonic_words[MAX_WORD_COUNT];

const char* mnemonic_get_word(uint8_t index);

#endif // MNEMONIC_TABLE_H
