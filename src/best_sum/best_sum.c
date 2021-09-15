#include <stdint.h>
#include <stdlib.h>
#include "debug.h"
#include "vector.h"
#include "linked_list.h"

    
    #define BEST_SUM_DEBUG_INTRO(_target_num, _a_num_array, _u_array_len, _p_memo_vec)                \
    DEBUG_PRINT_FUNCTION_START();                                                                    \
    DEBUG_PRINT("called as: how_sum(%d, [", _target_num);                                                       \
    for (size_t i = 0; i < _u_array_len; i++)                                                        \
    {                                                                                                \
        DEBUG_PRINT_NO_IDENT("%d, ", _a_num_array[i]);                                               \
    }                                                                                                \
    DEBUG_PRINT_NO_IDENT("], ");                                                                              \
    DEBUG_PRINT_NO_IDENT("p_memo_vec=\n");                                                                      \
    DEBUG_PRINT_LIST(_p_memo_vec);                                                               \
    DEBUG_PRINT_NO_IDENT(")\n");

// Vector* best_sum_brute(const uint32_t target_num, const uint32_t* const a_num_array, const uint32_t u_array_len, Vector *p_memo_vec)
// {

//     // BEST_SUM_DEBUG_INTRO(target_num, a_num_array, u_array_len, p_memo_vec);

//     Vector *p_ret_vec = NULL;

//     if (0 == target_num)
//     {
//         p_ret_vec = vector_init(0);
//     }
//     else if (target_num < 0)
//     {
//         DEBUG_PRINT("Target is less than 0.\n");
//         p_ret_vec = NULL;
//     }
//     else if (u_array_len == 0)
//     {
//         p_ret_vec = NULL;
//     }
//     else
//     {

//         Vector* p_shortest_combo = NULL;
//         for (uint32_t u_num_idx = 0; u_num_idx < u_array_len; u_num_idx++)
//         {
//             if (target_num >= a_num_array[u_num_idx])
//             {
//                 const uint32_t new_target = target_num - a_num_array[u_num_idx];
//                 Vector* p_new_target_combo = best_sum_brute(new_target, a_num_array, u_array_len, p_memo_vec);

//                 if (p_new_target_combo)
//                 {
//                     Vector* p_new_combo = vector_init_from_vector_and_add_num_and_clear_old(p_new_target_combo, a_num_array[u_num_idx]);
//                     if ((NULL == p_shortest_combo) || (p_shortest_combo && (p_new_combo->len < p_shortest_combo->len)))
//                     {
//                         p_shortest_combo = p_new_combo;
//                     }
                    
//                 }
//             }

//             // return NULL;
//         }

//         p_ret_vec = p_shortest_combo;
        
//     }

//     DEBUG_PRINT("I am returning:\n");
//     #ifdef DEBUG_PRINT_ON
//     DEBUG_PRINT_IDENT_ONLY();
//     vector_print(p_ret_vec);
//     DEBUG_PRINT_NO_IDENT("\n");
//     #endif
//     // DEBUG_PRINT("Trying to free: %p\n", p_memo_vec);
//     // vector_clear(p_memo_vec);
//     // p_memo_vec = NULL;
//     DEBUG_PRINT_FUNCTION_END();
//     return p_ret_vec;
    
// }

Vector* best_sum(const uint32_t target_num, const uint32_t* const a_num_array, const uint32_t u_array_len, volatile Node **p_memo_list)
{

    volatile Node* p_print = (*p_memo_list);
    BEST_SUM_DEBUG_INTRO(target_num, a_num_array, u_array_len, p_print);

    Vector *p_ret_vec = NULL;
    volatile Node* p_old_list_node = list_search(*p_memo_list, target_num);
    if (p_old_list_node)
    {
        p_ret_vec = p_old_list_node->p_vec;
    }
    else if (0 == target_num)
    {
        p_ret_vec = vector_init(0);
    }
    else
    {

        Vector* p_shortest_combo = NULL;
        for (uint32_t u_num_idx = 0; u_num_idx < u_array_len; u_num_idx++)
        {
            if (target_num >= a_num_array[u_num_idx])
            {
                const uint32_t new_target = target_num - a_num_array[u_num_idx];
                Vector* p_new_target_combo = best_sum(new_target, a_num_array, u_array_len, p_memo_list);

                if (p_new_target_combo)
                {
                    Vector* p_new_combo = vector_init_from_vector_and_add_num_and_clear_old(p_new_target_combo, a_num_array[u_num_idx]);
                    DEBUG_PRINT("New vector is: %p\n", p_new_combo);
                    matan_wait();
                    matan_wait();

                    
                    if ((NULL == p_shortest_combo) || (p_shortest_combo && (p_new_combo->len < p_shortest_combo->len)))
                    {
                        p_shortest_combo = p_new_combo;
                    }
                    
                }
            }

        }
        if (target_num == 19)
        {
            DEBUG_PRINT("LAST MEMO!!!\n");
            DEBUG_PRINT_LIST((*p_memo_list));
        }
        

        p_ret_vec = p_shortest_combo;
        
    }

    DEBUG_PRINT("Adding new memo:\n");

    if(p_old_list_node) // the target is in out list --> need to replace the node
    {
        DEBUG_PRINT("Replacing old node!\n");
        list_node_replace(p_old_list_node, p_ret_vec);
    }
    else
    {
        DEBUG_PRINT("Adding new node!\n");
        DEBUG_PRINT("target_sum = %d\n", target_num);
        if(p_ret_vec)
        {
            DEBUG_PRINT("p_ret_vec->p_vec->len = %d\n", p_ret_vec->len);
        }
        DEBUG_PRINT_IDENT_ONLY();
        DEBUG_PRINT_VECTOR(p_ret_vec);
        DEBUG_PRINT_NO_IDENT("\n");
        *p_memo_list = list_add_at_begining(*p_memo_list, target_num, p_ret_vec);
        
    }
    
    DEBUG_PRINT_FUNCTION_END();
    return p_ret_vec;
    
}

