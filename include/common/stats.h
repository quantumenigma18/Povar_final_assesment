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
 * @file stats.h
 * @brief Assigment1
 *
 * <Header file>
 *
 * @author Tetiana Povar
 * @date 01.05.2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */


/**
 * @brief <Print the statistics of the array to the screan >
 *
 * <Print  Median,Meam, Max, Min of the array>
 *
 * @param <array> <pointer to the array>
 * @param <Add InputName> <length of the array>
 *
 *
 * @return <void>
 */
void print_statistics(unsigned char *array, unsigned int length);
/**
 * @brief <Print the array to the screan>
 *
 * <Print the array to the screan>
 *
 * @param <array> <pointer to the array>
 * @param <Add InputName> <length of the array>
 *
 *
 * @return <void>
 */
void print_array(unsigned char *array, unsigned int length);

/**
 * @brief <Sort the array from largest to smallest>
 *
 * <Sorts the array from largest to smallest>
 *
 * @param <array> <pointer to the array>
 * @param <Add InputName> <length of the array>
 *
 *
 * @return <void>
 */
void sort_array(unsigned char *array, unsigned int length);

/**
 * @brief <Find median of the array>
 *
 * <Find median of the array>
 *
 * @param <array> <pointer to the array>
 * @param <Add InputName> <length of the array>
 *
 *
 * @return <value of median>
 */
int find_median(unsigned char *array, unsigned int length);

/**
 * @brief <Find mean of the array>
 *
 * <Find mean of the array>
 *
 * @param <array> <pointer to the array>
 * @param <Add InputName> <length of the array>
 *
 *
 * @return <value of meam>
 */
int find_mean(unsigned char *array, unsigned int length);

/**
 * @brief <Find maximum of the array>
 *
 * <Find maximum of the array>
 *
 * @param <array> <pointer to the array>
 * @param <Add InputName> <length of the array>
 *
 *
 * @return <value of maximum>
 */
int find_maximum(unsigned char *array, unsigned int length);

/**
 * @brief <Find minimum of the array>
 *
 * <Find minimum of the array>
 *
 * @param <array> <pointer to the array>
 * @param <Add InputName> <length of the array>
 *
 *
 * @return <value of minimum>
 */
int find_minimum(unsigned char *array, unsigned int length);








#endif /* __STATS_H__ */
