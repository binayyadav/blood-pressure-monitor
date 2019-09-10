#include "file.h"

filedb *file_load(FILE *file_in)
{

    filedb *db = (filedb *)malloc(sizeof(filedb));
    db->line_count = file_line_count(file_in);
    db->data = (uint8_t **)calloc(sizeof(uint8_t *),db->file_length);
}


uint16_t file_line_count(FILE *file_in)
{
    int ch;
    uint16_t lcnt = 0;
    uint16_t chcnt = 0;
    while((ch = getc(file_in))!=EOF)
    {
        if((uint8_t)ch == '\n')
        {
            lcnt++;
        }
    }
    rewind(file_in);
    return lcnt;
}

