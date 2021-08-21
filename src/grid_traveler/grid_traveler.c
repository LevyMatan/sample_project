#include <stdint.h>
#include <stdlib.h>
#include "grid_traveler.h"

#define FALSE (0)
#define TRUE  (1)

uint32_t get_grid_path_memo_private(const uint32_t m, const uint32_t n, Matrix *p_mat_grid_traveler_paths)
{
    if(NULL == p_mat_grid_traveler_paths)
    {
        return 0;
    }
    else
    {
        if(get_matrix_value(p_mat_grid_traveler_paths, m-1, n-1) == 0)
        {
            set_matrix_value(p_mat_grid_traveler_paths, m-1, n-1, grid_traveler(m, n, p_mat_grid_traveler_paths));
        }
        return get_matrix_value(p_mat_grid_traveler_paths, m-1, n-1);
    }
    
}


uint32_t grid_traveler(const uint32_t m, const uint32_t n, Matrix *p_mat_grid_traveler_paths)
{
    // Edge case
    uint32_t number_of_paths = 0;
    if ((m == 0) || (n == 0))
    {
        ;
    }
    else if ((m == 1) || (n == 1))
    {
        number_of_paths = 1;
    }
    else
    {
        uint32_t b_i_allocated_mem = FALSE;
        if(NULL == p_mat_grid_traveler_paths)
        {
            p_mat_grid_traveler_paths = matrix_init(m, n);
            
            b_i_allocated_mem = TRUE;
        }
        number_of_paths = get_grid_path_memo_private(m-1, n, p_mat_grid_traveler_paths) + get_grid_path_memo_private(m, n-1, p_mat_grid_traveler_paths);

        if (b_i_allocated_mem)
        {
            matrix_clear(p_mat_grid_traveler_paths);
            free(p_mat_grid_traveler_paths);
        }
        
    }
    
    return number_of_paths;
}


