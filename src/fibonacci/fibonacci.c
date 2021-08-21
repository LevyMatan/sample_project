
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief 
 * 
 * @param n 
 * @return uint32_t when returned 0, error occured allocating memory for the fibonacci sequence, otherwise the returned value is the n'th fibonacci number.
 */
uint32_t fib(const uint32_t n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        uint32_t *a_fib = (uint32_t*)malloc(sizeof(uint32_t) * n);
        if(NULL == a_fib)
        {
            return 0;
        }

        // Initialize the first numbers in the sequence
        a_fib[0] = 1;
        a_fib[1] = 1;

        // Loop over all numbers until reaching n
        for (uint32_t u_fib_idx = 3; u_fib_idx <= n; u_fib_idx++)
        {
            a_fib[u_fib_idx-1] = a_fib[u_fib_idx-2] + a_fib[u_fib_idx-3];
        }

        uint32_t u_fib_num = a_fib[n-1];

        free(a_fib);
        return u_fib_num;
        
    }
    



}
