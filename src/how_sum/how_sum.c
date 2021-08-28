#include <stdint.h>
#include <stdlib.h>
#include "debug.h"
#include "vector.h"

    
    #define HOW_SUM_DEBUG_INTRO(_target_num, _a_num_array, _u_array_len, _p_memo_vec)                \
    DEBUG_PRINT_FUNCTION_START();                                                                    \
    DEBUG_PRINT("called as: how_sum(%d, [", _target_num);                                                       \
    for (size_t i = 0; i < _u_array_len; i++)                                                        \
    {                                                                                                \
        DEBUG_PRINT_NO_IDENT("%d, ", _a_num_array[i]);                                               \
    }                                                                                                \
    DEBUG_PRINT_NO_IDENT("], ");                                                                              \
    DEBUG_PRINT_NO_IDENT("p_memo_vec=");                                                                      \
    DEBUG_PRINT_VECTOR(_p_memo_vec);                                                                 \
    DEBUG_PRINT_NO_IDENT(")\n");

Vector* how_sum(const uint32_t target_num, const uint32_t* const a_num_array, const uint32_t u_array_len, Vector *p_memo_vec)
{

    HOW_SUM_DEBUG_INTRO(target_num, a_num_array, u_array_len, p_memo_vec);

    Vector *p_ret_vec = NULL;

    if (0 == target_num)
    {
        DEBUG_PRINT("Found my sum!\n");
        p_ret_vec = vector_init_from_vector(p_memo_vec);
    }
    else if (0 == u_array_len)
    {
        DEBUG_PRINT("Target is greater then 0 and input array is empty\n");
    }
    else
    {
        if (target_num >= a_num_array[0])
        {
            DEBUG_PRINT("p_memo_vec = %p\n", p_memo_vec);
            if(p_memo_vec)
            {
                DEBUG_PRINT("p_memo_vec->len = %d\n", p_memo_vec->len);
                DEBUG_PRINT("p_memo_vec      = ");
                DEBUG_PRINT_VECTOR(p_memo_vec);
                DEBUG_PRINT_NO_IDENT("\n");
            }
            Vector *p_extended_memo = vector_init_from_vector_and_add_num(p_memo_vec, a_num_array[0]);
            p_ret_vec = how_sum(target_num - a_num_array[0], (a_num_array), (u_array_len), p_extended_memo);
            if (p_ret_vec)
            {
                DEBUG_PRINT("Trying to free: %p\n", p_memo_vec);
                vector_clear(p_memo_vec);
                p_memo_vec = NULL;
            }
            if(NULL == p_ret_vec)
            {
                p_ret_vec = how_sum(target_num - a_num_array[0], (a_num_array+1), (u_array_len-1), p_extended_memo);
                if (p_ret_vec)
                {
                    DEBUG_PRINT("Trying to free: %p\n", p_memo_vec);
                    vector_clear(p_memo_vec);
                    p_memo_vec = NULL;
                }
            }
            
        }
        else
        {
            DEBUG_PRINT("Next number is greater than target: NULL\n");
        }
           
        if(NULL == p_ret_vec)
        {
            p_ret_vec = how_sum(target_num, (a_num_array+1), (u_array_len-1), p_memo_vec);
        }
        else
        {
            DEBUG_PRINT("Already found another path\n");
        }
        
    }

    DEBUG_PRINT("I am returning:\n");
    #ifdef DEBUG_PRINT_ON
    DEBUG_PRINT_IDENT_ONLY();
    vector_print(p_ret_vec);
    DEBUG_PRINT_NO_IDENT("\n");
    #endif
    // DEBUG_PRINT("Trying to free: %p\n", p_memo_vec);
    // vector_clear(p_memo_vec);
    // p_memo_vec = NULL;
    DEBUG_PRINT_FUNCTION_END();
    return p_ret_vec;
    
}

