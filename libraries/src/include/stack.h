#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

#define STACK_OVERRUN  1
#define STACK_UNDERRUN 2

typedef struct stack_tag
{
    void *ptr;
    void *top;
    uint16_t depth;
    size_t element_size;
}stack;

stack* stack_new(void *top, size_t element_size, uint16_t stack_depth);
uint8_t stack_push(stack *pstk, void *data);

#endif //STACK_H
