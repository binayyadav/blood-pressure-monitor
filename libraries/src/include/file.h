#ifndef FILE_LOAD_H
#define FILE_LOAD_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct filedb_tag
{
    uint16_t *line_length;
    uint16_t line_length_max;
    uint16_t line_count;
    uint8_t *name;
    uint8_t **data;
}filedb;

filedb *file_load(FILE *file_in);
uint8_t file_line_count(FILE *file_in);
#endif //FILE_LOAD_H

