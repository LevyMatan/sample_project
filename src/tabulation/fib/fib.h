/**
 * @file fib.h
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief Write a function 'fib(n)' that takes in a number as an argument.
 *        The function should return the n-th number of the Fibonacci sequence.
 * 
 *        The 0th number of the sequence is 0.
 *        The 1th number of the sequence is 1.
 * 
 *        To generate the next number of the sequence, we sum the two last numbers in the sequence.
 * 
 * @version 0.1
 * @date 2021-09-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __FIB_H__
#define __FIB_H__

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 
    
uint32_t fib_tabulation(uint32_t u_num);

#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__FIB_H__
