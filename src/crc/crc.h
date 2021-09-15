#ifndef __CRC_H__
#define __CRC_H__
#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 

/**
 * @brief Get the left most bit object
 *        from a given number.
 *        returns the same number only with the left most bit set. 
 * 
 * @param u_num The number to get the left most bit from
 * @return uint32_t 
 */
uint32_t get_left_most_bit(uint32_t u_num);

/**
 * @brief Get the bit idx object
 *        Assume that u_num has one and only one bit set.
 * 
 * @param u_num 
 * @return uint32_t 
 */
uint32_t get_bit_idx(uint32_t u_num);

/**
 * @brief Compute the CRC of a given data.
 *        Using a defualt polynomial of 0x1021.
 * 
 * @param u_data 
 * @return uint16_t 
 */
uint16_t crc16_ccitt(uint16_t u_data);

#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__CRC_H__