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
 * @file stats.c
 * @brief Assignment1
 *
 * <Source file>
 *
 * @author Tetiana Povar
 * @date 01.05.2020
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/* Add other Implementation File Code Here */

void print_array(unsigned char *array, unsigned int length)
{
   #ifdef VERBOSE
        PRINTF("Array:");
        for(unsigned int i = 0;i<length; i++)
        {
            PRINTF("%d ",array[i]);
        }
    #endif
}

void sort_array(unsigned char *array, unsigned int length)
{
    unsigned char adv = 0;
    for( unsigned int i = 0; i<length; i++)
    {
        for(unsigned int j = 0; j<length-i-1; j++)
        {
            if(array[j]<array[j+1])
            {
                adv = array[j];
                array[j] = array[j+1];
                array[j+1] =adv;
            }
        }
    }
    
}

int find_median(unsigned char *array, unsigned int length)
{
    unsigned char median = 0;
    sort_array(array,length);
    if(length%2!=0)
    {
        median = array[length/2];
    }
    else
    {
        median = (array[length/2] + array[length/2+1])/2;
    }
    return median;
}

int find_mean(unsigned char *array, unsigned int length)
{
    unsigned char mean = 0;
    unsigned int sum =0;
    for( unsigned int i = 0; i<length; i++)
    {
        sum += array[i];
    }
    return mean = sum/length;
}
int find_maximum(unsigned char *array, unsigned int length)
{
    sort_array(array,length);
    return array[0];
}

int find_minimum(unsigned char *array, unsigned int length)
{
    sort_array(array,length);
    return array[length-1];
    
}
void print_statistics(unsigned char *array, unsigned int length)
{
    //unsigned char median = find_median(array,length);
    //unsigned char mean = find_mean(array,length);
    //unsigned char max = find_maximum(array,length);
    //unsigned char min = find_minimum(array,length);
    PRINTF("\nMedian %d,\nMean %d,\nMaximun %d,\nMinimum  %d,\n",find_median(array,length),find_mean(array,length),find_maximum(array,length),find_minimum(array,length));
    
}


