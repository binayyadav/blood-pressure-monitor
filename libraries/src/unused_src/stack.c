#include "stack.h"

stack* stack_new(void *top, size_t element_size, uint16_t stack_depth) {
    stack *pstk = (stack *)malloc(sizeof(stack));
    pstk->element_size = element_size;
    pstk->depth = stack_depth;
    pstk->top = top;
    pstk->ptr = top;
    uint16_t bytecnt = element_size * stack_depth;
    uint16_t index;
    for(index = 0; index < bytecnt; index++) {
        *((uint8_t*)pstk->top+index) = 0 ;
    } 
    return pstk;
}
uint8_t stack_isfull(stack *pstk) {
    if(pstk->element_size * pstk->depth == 0) {}
}
uint8_t stack_push(stack *pstk, void *data) {
    uint16_t index = 0;
    for(index = 0; index < pstk->element_size; index++) {
        *((uint8_t*)pstk->ptr+index) = *((uint8_t*)data+index);
    } 
    pstk->ptr+=pstk->element_size;
}
uint8_t stack_pop(stack *pstk, void *data) {
    uint16_t index;
    pstk->ptr-=pstk->element_size;
    for(index = 0; index < pstk->element_size; index++) {
        *((uint8_t*)data+index) = *((uint8_t*)pstk->ptr+index);
    } 
    return 0;
}
