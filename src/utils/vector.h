#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdint.h>
#include <stdio.h>


#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 
    
struct vector_s{
    uint32_t len; // Number of rows

    uint32_t *p_vec;
};

typedef struct vector_s Vector;


Vector* vector_init(const uint32_t len);
Vector* vector_deep_copy(Vector *p_vec_to_copy);
Vector* vector_init_from_vector(Vector *p_vec_to_copy);
Vector* vector_init_from_vector_and_add_num(Vector *p_vec_to_copy, const uint32_t u_val);
Vector* vector_init_from_vector_and_add_num_and_clear_old(Vector *p_vec_to_copy, const uint32_t u_val);

void vector_clear(Vector *p_vec);

uint32_t get_vector_value(Vector *p_vec, const uint32_t elem_idx);
void set_vector_value(Vector *p_vec, const uint32_t elem_idx, const uint32_t val);

void vector_print(Vector *p_vec);

#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__VECTOR_H__
