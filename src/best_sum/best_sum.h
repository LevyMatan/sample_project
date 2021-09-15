/**
 * @file best_sum.h
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief Write a function 'best_sum(target_sum, numbers)' that take in a target_sum and an array of numbers as arguments.
 * 
 *        The function should return an array containing the #shortest# combination of numbers that add up to exactly the target_sum.
 * 
 *        If there is a tie for the shortest combination, you may return any one of the shortest.
 * 
 *        Examples:
 *        1) best_sum(7, [2, 3, 5]) -->
 *           * X [2, 2, 2, 2]
 *           * X [2, 3, 3]
 *           * V [3, 5]
 *        2) best_sum()
 * @version 0.1
 * @date 2021-08-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __BEST_SUM_H__
#define __BEST_SUM_H__

#include <stdint.h>
#include "vector.h"
#include "linked_list.h"


#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 

/**
 * @brief Psedo code for easier cases!
 * 
 * @param target_num 
 * @param a_num_array 
 * @param u_array_len 
 * @param p_memo_vec 
 * @return Vector* 
 */
Vector* best_sum(const uint32_t target_num, const uint32_t* const a_num_array, const uint32_t u_array_len, Node** p_memo_list);
/**
 * @brief   brute force
 *          if(target_num == 0) return [];
 *          if(target_num < 0) return null;
 *          
 *          var shortest_combination = null;
 *          for(num in a_num_array)
 *          {
 *              reminder = target_num - num;
 *              reminder_result = best_sum(reminder, a_num_array)
 *              if (reminder_result != NULL)
 *              {
 *                  combination = [reminder_result, num];
 *                  if((shortest_combination == NULL) || (len(combination) < len(shortest_combination)))
 *                  {
 *                      shortest_combination = combination
 *                  }
 *              }
 *           }
 *           
 *          return shortest_combnation
 */     

#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__BEST_SUM_H__
