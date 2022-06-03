
#include <stdint.h>
#include <stdlib.h>


uint32_t fib_tabulation(uint32_t u_num)
{
    uint32_t *p_array = (uint32_t *)calloc(sizeof(uint32_t) * (u_num + 1));
    p_array[0] = 0;
    p_array[1] = 1;
    for (uint32_t i = 2; i <= u_num; i++)
    {
        p_array[i] = p_array[i - 1] + p_array[i - 2];
    }
    uint32_t u_result = p_array[u_num];
    free(p_array);
    return u_result;
}
