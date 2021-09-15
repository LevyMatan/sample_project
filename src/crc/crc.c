#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "debug.h"


/**
 * @brief Get the left most bit object
 *        from a given number.
 *        returns the same number only with the left most bit set. 
 * 
 * @param u_num The number to get the left most bit from
 * @return uint32_t 
 */
uint32_t get_left_most_bit(uint32_t u_num)
{
    
    u_num |= (u_num >> 1);
    u_num |= (u_num >> 2);
    u_num |= (u_num >> 4);
    u_num |= (u_num >> 8);
    u_num |= (u_num >> 16);

    uint64_t u_num_extened = u_num + 1;
    u_num = (uint32_t)(u_num_extened >> 1); 
    return u_num;
}

/**
 * @brief Get the bit idx object
 *        Assume that u_num has one and only one bit set.
 * 
 * @param u_num 
 * @return uint32_t 
 */
uint32_t get_bit_idx(uint32_t u_num)
{
    uint32_t u_bit_idx = 0;

    while(u_num >>= 1)
    {
        u_bit_idx++;
    }

    return u_bit_idx;
}

uint16_t crc16_ccitt(uint16_t u_data)
{
    DEBUG_PRINT_FUNCTION_START();
    DEBUG_PRINT("u_data = %u\n", u_data);

    const uint32_t u_poly_coefs = 0x11021;
    uint32_t u_num = u_data << 16;

    uint32_t u_left_most_bit_set = get_left_most_bit(u_num);
    DEBUG_PRINT("u_left_most_bit_set = 0x%08x\n", u_left_most_bit_set);

    uint32_t u_bit_idx = get_bit_idx(u_left_most_bit_set);
    DEBUG_PRINT("u_left_most_bit_set = %d\n", u_bit_idx);
    while (u_bit_idx > 15)
    {
        DEBUG_PRINT("=============================\n");
        const uint32_t u_updated_poly_coefs = u_poly_coefs << (u_bit_idx - 16);
        DEBUG_PRINT("u_updated_poly_coefs = 0x%08x\n", u_updated_poly_coefs);
        u_num = u_num ^ u_updated_poly_coefs;
        DEBUG_PRINT("u_num = 0x%08x\n", u_num);
        u_left_most_bit_set = get_left_most_bit(u_num);
        DEBUG_PRINT("u_left_most_bit_set = 0x%08x\n", u_left_most_bit_set);
        u_bit_idx = get_bit_idx(u_left_most_bit_set);
        DEBUG_PRINT("u_left_most_bit_set = %d\n", u_bit_idx);
    }
    
    const uint16_t u_crc = (uint16_t)(u_num & 0x0000FFFF);

    DEBUG_PRINT_FUNCTION_END();

    return u_crc;
}