#ifndef POSIX_HELPER_H
#define POSIX_HELPER_H

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum posix_character_class_tag
{
    alnum, // [A-Za-z0-9]
    alpha, // [A-Za-z]
    blank, // [ \t]
    cntrl, // [\x00-\x1F\x7F]
    digit, // [0-9]
    graph, // [\x21-\x7E]
    lower, // [a-z]
    print, // [\x20-\x7E]
    punct, // [\]\[!"#$%&'()*+,./:;<=>?@\^_`{|}~-]
    space, // [ \t\r\n\v\f] "0x20 0x09 0x0d 0x0a 0x0b 0x0c"
    upper, // [A-Z]
    xdigit, // [A-Fa-f0-9]
    tknmax
}posix_character_class;

#define TKN_STR_LEN 60
typedef struct posix_token_tag
{
    posix_character_class tkn_class;
    uint8_t tkn_value;
    char *tkn_str;
}posix_token;

posix_token* posix_tknch(const char *str);

posix_token* posix_token_load(FILE *file_in);
// Pass this function one token at a time please
posix_token* posix_tokenizer(const char *str);

#endif //POSIX_HELPER_H
