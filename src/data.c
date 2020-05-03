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

/* Size of the Data Set */
#define SIZE (40)

void main() {
    
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
        114, 88,   45,  76, 123,  87,  25,  23,
        200, 122, 150, 90,   92,  87, 177, 244,
        201,   6,  12,  60,   8,   2,   5,  67,
        7,  87, 250, 230,  99,   3, 100,  90};
    
    print_array(test,SIZE);
    print_statistics(test,SIZE);
    sort_array(test,SIZE);
    print_array(test,SIZE);
    
}
/* Add other Implementation File Code Here */
void print_statistics(unsigned char *array, unsigned int length)
{
    unsigned char median,mean,max,min;
    median = find_median(array,length);
    mean = find_mean(array,length);
    max = find_maximum(array,length);
    min = find_minimum(array,length);
    printf("\nMedian %d,\nMean %d,\nMaximun %d,\nMinimum  %d,\n",median,mean,max,min);
    
}

void print_array(unsigned char *array, unsigned int length)
{
    printf("Array:");
    for(unsigned int i = 0;i<length; i++)
    {
        printf("%d ",array[i]);
    }
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


