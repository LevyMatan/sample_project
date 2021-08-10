#ifndef __GET_RX_TX_MASK_H__
#define __GET_RX_TX_MASK_H__

#include <stdint.h>
#include <stdio.h>

#define BITMASK_OF_LENGTH(x) ( (1 << (x)) - 1)
#define DIVIDE_BY_32(x)      ( (x) >> 5      )
#define MIN(x,y)             (((x) < (y)) ? (x) : (y) )

#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 
    
uint32_t get_rx_tx_mask(uint32_t a_rx_tx_mask_array[] , const uint32_t payload_index, const uint32_t number_of_payloads);

#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__GET_RX_TX_MASK_H__
