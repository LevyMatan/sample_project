#include <stdint.h>
#include <stdlib.h>
#include "vector.h"
#include "debug.h"

#define DEBUG_PRINT_ON

Vector* vector_init(const uint32_t len)
{
    DEBUG_PRINT_FUNCTION_START();
    // DEBUG_PRINT("p_vec_to_copy = %p\n", p_vec_to_copy);
    // if(p_vec_to_copy)
    // {
    //     DEBUG_PRINT("p_vec_to_copy->len = %d\n", p_vec_to_copy->len);
    //     DEBUG_PRINT("p_vec_to_copy      = ");
    //     DEBUG_PRINT_VECTOR(p_vec_to_copy);
    //     DEBUG_PRINT_NO_IDENT("\n");
    // }
    Vector *p_new_vec = (Vector*)calloc(1, sizeof(Vector));
    p_new_vec->len = len;
    p_new_vec->p_vec = (0 == len) ? (NULL) : (uint32_t*)calloc(len, sizeof(uint32_t));

    DEBUG_PRINT_FUNCTION_END();
    return p_new_vec;

}


Vector* vector_deep_copy(Vector *p_vec_to_copy)
{
    DEBUG_PRINT_FUNCTION_START();
    Vector *p_new_vec = NULL;

    if (p_vec_to_copy)
    {
        p_new_vec = (Vector*)calloc(1, sizeof(Vector));
        p_new_vec->len = p_vec_to_copy->len;
        p_new_vec->p_vec = (0 == p_vec_to_copy->len) ? NULL : (uint32_t*)calloc(p_vec_to_copy->len, sizeof(uint32_t));

        for (uint32_t i = 0; i < p_vec_to_copy->len; i++)
        {
            p_new_vec->p_vec[i] = p_vec_to_copy->p_vec[i];
        }
    }
    
    DEBUG_PRINT_FUNCTION_END();
    return p_new_vec;
}

Vector* vector_init_from_vector(Vector *p_vec_to_copy)
{
    DEBUG_PRINT_FUNCTION_START();
    // DEBUG_PRINT("p_vec_to_copy = %p\n", p_vec_to_copy);
    // if(p_vec_to_copy)
    // {
    //     DEBUG_PRINT("p_vec_to_copy->len = %d\n", p_vec_to_copy->len);
    //     DEBUG_PRINT("p_vec_to_copy      = ");
    //     DEBUG_PRINT_VECTOR(p_vec_to_copy);
    //     DEBUG_PRINT_NO_IDENT("\n");
    // }
    Vector *p_new_vec = (Vector*)calloc(1, sizeof(Vector));
    uint32_t u_new_len = 0;

    if (p_vec_to_copy)
    {
        u_new_len = p_vec_to_copy->len + 1;
        p_new_vec->len = u_new_len;
        p_new_vec->p_vec = (uint32_t*)realloc(p_vec_to_copy->p_vec, sizeof(uint32_t));
        p_vec_to_copy->p_vec = NULL;
    }
    DEBUG_PRINT_FUNCTION_END();
    return p_new_vec;

}

Vector* vector_init_from_vector_and_add_num(Vector *p_vec_to_copy, const uint32_t u_val)
{
    DEBUG_PRINT_FUNCTION_START();
    // DEBUG_PRINT("p_vec_to_copy = %p\n", p_vec_to_copy);
    // if(p_vec_to_copy)
    // {
    //     DEBUG_PRINT("p_vec_to_copy->len = %d\n", p_vec_to_copy->len);
    //     DEBUG_PRINT("p_vec_to_copy      = ");
    //     DEBUG_PRINT_VECTOR(p_vec_to_copy);
    //     DEBUG_PRINT_NO_IDENT("\n");
    // }
    Vector *p_new_vec = NULL;
    if (p_vec_to_copy)
    {
        p_new_vec = vector_deep_copy(p_vec_to_copy);
        p_new_vec = vector_init_from_vector(p_new_vec);
    }
    else
    {
        p_new_vec = (Vector*)calloc(1, sizeof(Vector));
        p_new_vec->len = 1;
        p_new_vec->p_vec = (uint32_t*)calloc(p_new_vec->len, sizeof(uint32_t));
    }
    
    // DEBUG_PRINT("p_new_vec->p_vec[p_new_vec->len - 1] = u_val\n");
    // DEBUG_PRINT("p_new_vec->len - 1 = %d\n", p_new_vec->len - 1);
    // DEBUG_PRINT("p_new_vec->p_vec[p_new_vec->len - 1] = %d\n", p_new_vec->p_vec[p_new_vec->len - 1]);
    // DEBUG_PRINT("u_val = %d\n" , u_val);
    p_new_vec->p_vec[p_new_vec->len - 1] = u_val;
    
    DEBUG_PRINT_FUNCTION_END();
    return p_new_vec;
}
Vector* vector_init_from_vector_and_add_num_and_clear_old(Vector *p_vec_to_copy, const uint32_t u_val)
{
    DEBUG_PRINT_FUNCTION_START();
    // DEBUG_PRINT("p_vec_to_copy = %p\n", p_vec_to_copy);
    // if(p_vec_to_copy)
    // {
    //     DEBUG_PRINT("p_vec_to_copy->len = %d\n", p_vec_to_copy->len);
    //     DEBUG_PRINT("p_vec_to_copy      = ");
    //     DEBUG_PRINT_VECTOR(p_vec_to_copy);
    //     DEBUG_PRINT_NO_IDENT("\n");
    // }
    Vector *p_new_vec = vector_init_from_vector_and_add_num(p_vec_to_copy, u_val);
    // vector_clear(p_vec_to_copy);
    
    DEBUG_PRINT_FUNCTION_END();
    return p_new_vec;
}

void vector_clear(Vector *p_vec)
{
    DEBUG_PRINT_FUNCTION_START();
    if (p_vec)
    {
        DEBUG_PRINT("Trying to free: %p\n", p_vec->p_vec);
        matan_wait();
        matan_wait();
        matan_wait();
        if (p_vec->p_vec)
        {
            free(p_vec->p_vec);
            DEBUG_PRINT("Success to free: %p\n", p_vec->p_vec);
            matan_wait();
            matan_wait();
            matan_wait();
        }
        DEBUG_PRINT("Trying to free: %p\n", p_vec);
        matan_wait();
        matan_wait();
        matan_wait();
        free(p_vec);
    }
    
    DEBUG_PRINT_FUNCTION_END();
}

uint32_t get_vector_value(Vector *p_vec, const uint32_t elem_idx)
{
    if (p_vec && p_vec->p_vec)
    {
        if (elem_idx < p_vec->len)
        {
            return p_vec->p_vec[elem_idx];
        }
        
    }

    return UINT32_MAX;
    
}
void set_vector_value(Vector *p_vec, const uint32_t elem_idx, const uint32_t val)
{
    if (p_vec && p_vec->p_vec)
    {
        if (elem_idx < p_vec->len)
        {
            p_vec->p_vec[elem_idx] = val;
        }
        
    }
    
}

void vector_print(Vector *p_vec)
{
    if (p_vec)
    {
        printf("[");
        if (p_vec->len > 0)
        {
            for (size_t i = 0; i < (p_vec->len - 1); i++)
            {
                printf("%d, ", get_vector_value(p_vec, i));
            }
            printf("%d ", get_vector_value(p_vec, p_vec->len - 1));
        }
        
        printf("]");
    }
    else
    {
        printf("NULL");
    }
    
    
}

