
#include <stdint.h>
#include "get_rx_tx_mask.h"

#define MAX_PAYLOADS        (10U)
#define NUM_OF_BITS_IN_WORD (32U)
#define ERROR_MSG           (0xFFFFFFFF)

uint32_t get_rx_tx_mask(uint32_t a_rx_tx_mask_array[] , const uint32_t payload_index, const uint32_t number_of_payloads)
{
    if(number_of_payloads > MAX_PAYLOADS)
    {
        return ERROR_MSG;
    }
    // INPUT validation

    
    // uint32_t word_idx = payload_index / 32;
    // uint32_t bit_idx  = payload_index % 32;
    uint32_t word_idx = DIVIDE_BY_32(payload_index);
    uint32_t bit_idx  = payload_index & BITMASK_OF_LENGTH(5);
    
    
    // First word to contain relevant indicators
    ////////////////////////////////////////////
    
    // Compute how many indicator bits are in the first word
    uint32_t number_of_payloads_0 = MIN((NUM_OF_BITS_IN_WORD - bit_idx), (number_of_payloads));
    
    // Create a mask of N bits, according to payloads of the first word
    uint32_t mask_0 = BITMASK_OF_LENGTH(number_of_payloads_0); 
    
    // Align the input to the first relevant bit
    uint32_t input_mask = a_rx_tx_mask_array[word_idx] >> bit_idx;
    
    // Cancel out all unwanted bits
    uint32_t output_mask = (input_mask & mask_0);
    
    // Mask is spread on 2 words
    if(bit_idx + number_of_payloads > NUM_OF_BITS_IN_WORD)
    {
        // Compute how many indicator bits are in the second word
        uint32_t number_of_payloads_1 = number_of_payloads - number_of_payloads_0;
        
        // Create a mask of N bits, according to payloads of the first word
        uint32_t mask_1 = BITMASK_OF_LENGTH(number_of_payloads_1);
        
        // In this case, the first bit is always 0-indexed so the data is aligned
        uint32_t output_mask_1 = (a_rx_tx_mask_array[word_idx+1] & mask_1);
        
        // Combine both words mask into one
        output_mask = ((output_mask_1 << (number_of_payloads_0)) | output_mask);
        
    }

    return output_mask;

}
