/**
 * @file hamming_code.c
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief This model will try to implement a Hamming code encoder and decoder.
 * @version 0.1
 * @date 2022-07-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "hamming_code.hpp"
#include <iostream>
HammingCodeConfigurations::HammingCodeConfigurations(const uint32_t u_num_of_redundant_bits)
{
    if (u_num_of_redundant_bits <= MAX_ALLOWED_REDUDNAT_BITS)
    {
        this->u_num_of_redundant_bits = u_num_of_redundant_bits;
        this->u_code_size = (1U << u_num_of_redundant_bits);
    }
    else
    {
        throw HammingCodeConfigurationsException();
    }
}

uint32_t HammingCodeConfigurations::get_num_of_redundant_bits()
{
    return this->u_num_of_redundant_bits;
}

uint32_t HammingCodeConfigurations::get_code_size()
{
    return this->u_code_size;
}

HammingDecoder::HammingDecoder(HammingCodeConfigurations configs) : configurations(configs.get_num_of_redundant_bits())
{
    std::cout << "HammingDecoder::HammingDecoder(HammingCodeConfigurations configs)" << std::endl;

    // Initialize the decoders parity bits locations
}
