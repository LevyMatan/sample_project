#include <stdint.h>
#include <stdlib.h>

#define FALSE (0)
#define TRUE  (1)

uint32_t can_sum(const uint32_t target_num, const uint32_t* const a_num_array, const uint32_t u_array_len)
{
    if(u_array_len == 0)
    {
        return FALSE;
    }
    else if (target_num == 0)
    {
        return TRUE;
    }
    else
    {
        if (target_num == a_num_array[0])
        {
            return TRUE;
        }
        else
        {
            uint32_t b_can_sum = can_sum(target_num, (a_num_array+1), (u_array_len-1));

            if (target_num > a_num_array[0])
            {
                b_can_sum |= can_sum(target_num - a_num_array[0], (a_num_array+1), (u_array_len-1)); 
            }
            
            return b_can_sum;
        }
        
    }
    
}

