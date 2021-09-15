/**
 * @file how_sum.h
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief Write a function how_sum(target_sum, array) that takes in a target_sum and an array of numbers as argument.
          The function should return an array containing any combination of elements that add up to exactly the target_sum.
          If there is no combination that adds up to the target_sum, then return NULL.

          If there are multiple combinations possible, you may return any single one.

          Example:
          1) how_sum(target_sum=7, array=[5, 3, 4, 7])
          there are two possible outcomes:
          * [3, 4]
          * [7]

          2) how_sum(target_sum=8, array=[2, 3, 5])
          * [2, 2, 2, 2]
          * [3, 5]
          
          3) how_sum(target_sum=7, array=[2, 4])
          * NULL
          
          4) how_sum(target_sum=0, array=[2, 4])
          * []


          Time and Space complexity analysis: (with Memozation)
          m = target
          n = array length
          Time = O(n * m^2)
          Space = O(m^2)
 * @version 0.1
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __HOW_SUM_H__
#define __HOW_SUM_H__

#include <stdint.h>
#include "vector.h"


#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 

/**
 * @brief Cuation!!! This function allocates memory! Caller must free this memory!
 * 
 * @param target_num 
 * @param a_num_array 
 * @param u_array_len 
 * @return uint32_t* 
 */
Vector* how_sum(const uint32_t target_num, const uint32_t* const a_num_array, const uint32_t u_array_len, Vector *p_memo_vec);

#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__HOW_SUM_H__
