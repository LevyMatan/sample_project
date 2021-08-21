#ifndef __GRID_TRAVELER_H__
#define __GRID_TRAVELER_H__

#include <stdint.h>
#include "matrix.h"

/**
 * @brief Say you are a traveler on a 2D grid.
 * You begin in the top-left corner and your goal is to travel to the bottom-right corner.
 * You may only move down or right.
 * In how many ways can you travel to the goal on a grid with dimensions m * n?
 * 
 * 
 */
#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 

/**
 * @brief Computes the number of unique paths to travel the grid when the only moves are right and down.
 * 
 * @param m number of rows in the grid
 * @param n number of columns in the grid
 * @return uint32_t the number of paths to travel from upper-left corner to the bottom-right corner
 */
uint32_t grid_traveler(const uint32_t m, const uint32_t n, Matrix *p_mat_grid_traveler_paths);


#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__GRID_TRAVELER_H__
