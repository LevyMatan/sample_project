#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdint.h>
#include <stdio.h>


#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 
    
struct matrix_2d{
    uint32_t m; // Number of rows
    uint32_t n; // Number of cols

    uint32_t *p_matrix;
};

typedef struct matrix_2d Matrix;


Matrix* matrix_init(const uint32_t rows, const uint32_t cols);
void matrix_clear(Matrix *p_mat);

uint32_t get_matrix_value(Matrix *p_mat, const uint32_t row_idx, const uint32_t col_idx);
void set_matrix_value(Matrix *p_mat, const uint32_t row_idx, const uint32_t col_idx, const uint32_t val);

#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__MATRIX_H__
