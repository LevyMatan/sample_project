#ifndef __CAN_SUM_H__
#define __CAN_SUM_H__

#include <stdint.h>


#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 

uint32_t can_sum(const uint32_t target_num, const uint32_t* const a_num_array, const uint32_t u_array_len);

#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__CAN_SUM_H__
