#include <stdint.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* matrix_init(const uint32_t rows, const uint32_t cols)
{
    Matrix *p_new_matrix = (Matrix*)calloc(1, sizeof(Matrix));

    p_new_matrix->m = rows;
    p_new_matrix->n = cols;

    p_new_matrix->p_matrix = (uint32_t*)calloc(rows*cols, sizeof(uint32_t));
    return p_new_matrix;
}


void matrix_clear(Matrix *p_mat)
{
    if(p_mat->p_matrix)
    {
        free(p_mat->p_matrix);
    }
    p_mat->p_matrix = NULL;
}

uint32_t get_matrix_value(Matrix *p_mat, const uint32_t row_idx, const uint32_t col_idx)
{
    const uint32_t linear_idx = row_idx*p_mat->n + col_idx;
    return p_mat->p_matrix[linear_idx];
}
void set_matrix_value(Matrix *p_mat, const uint32_t row_idx, const uint32_t col_idx, const uint32_t val)
{
    const uint32_t linear_idx = row_idx*p_mat->n + col_idx;
    p_mat->p_matrix[linear_idx] = val;
}
