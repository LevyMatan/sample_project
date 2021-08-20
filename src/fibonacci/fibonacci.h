#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 
    
/**
 * @brief 
 * 
 * @param n 
 * @return uint32_t when returned 0, error occured allocating memory for the fibonacci sequence, otherwise the returned value is the n'th fibonacci number.
 */
uint32_t fib(const uint32_t n);


#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__FIBONACCI_H__
