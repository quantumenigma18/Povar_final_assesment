/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Assignment4
 *
 * <Source file>
 *
 * @author Tetiana Povar
 * @date 03.05.2020
 *
 */



#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    int32_t adv;
    char no = 0;
    uint8_t i = 0,length =0;
    if(data == 0)
    {
        *(ptr + ++i) = '\0';
        return ++i;
    }
    
    *(ptr + i++) = '\0';
    
    if(data < 0 && base == 10)
    {
        no = 1;
        data = -data;
    }
    do {
        *(ptr + i) = data%base;
        i = ++i;
        data = data/base;
    }while( data != 0)
    
    if(no == 1) *(ptr + i++) = '-';
    length = i;
    uint8_t *ptr_adv= my_reverse(ptr,length);
    ptr = ptr_adv;
    return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int32_t data = 0;
    uint8_t i = digits-2;
    uint8_t adv = (uint8_t)base;
    base = 1;
    if(!ptr) return -1;
    while(i > 0) {
        data += *(ptr + i)*(base) ;
        i = --i;
        base*= adv;
    }
    
    if(adv == 10 && *(ptr + i) == '-')
        data = -data;
    else data += *(ptr + i)*(base);
    return data;
}
