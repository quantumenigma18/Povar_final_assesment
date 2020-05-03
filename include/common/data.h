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
 * @file data.h
 * @brief Assigment4
 *
 * <Header file>
 *
 * @author Tetiana Povar
 * @date 04.05.2020
 *
 */
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

#ifndef __DATA_H__
#define __DATA_H__

/* Add Your Declarations and Function Comments here */
/**
 * @brief onvert data from a standard integer type into an ASCII string.
 *
 * Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.All operations need to be performed using pointer arithmetic, not array indexing.The number you wish to convert is passed in as a signed 32-bit integer. You should be able to support bases 2 to 16 by specifying the integer value of the base you wish to convert to (base). Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr). The signed 32-bit number will have a maximum string size (Hint: Think base 2).You must place a null terminator at the end of the converted c-string.
 *
 * @param data 32-bit integer of data array
 * @param ptr 8-bit pointer.
 * @param base bases 2 to 16
 *
 * @return length of the string
 */



uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
/**
 * @brief convert data back from an ASCII represented string into an integer type.
 *
 * 
 *ASCII-to-Integer needs to convert data back from an ASCII represented string into an integer type.All operations need to be performed using pointer arithmetic, not array indexing
 *
 * @param ptr 8-bit pointer.
 * @param digits 32-bit integer
 * @param base bases 2 to 16
 *
 * @return data 32-bit integer of data array
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __STATS_H__ */
