/**
 * @file hamming_code.hpp
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief Hamming Code
 * @version 0.1
 * @date 2022-07-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __HAMMING_CODE_H__
#define __HAMMING_CODE_H__

#include <cstdint>
#include <exception>


#define MAX_ALLOWED_REDUDNAT_BITS                              (10)

class HammingCodeConfigurations
{
private:
    uint32_t u_num_of_redundant_bits;
    uint32_t u_code_size;
public:
    HammingCodeConfigurations(uint32_t u_num_of_redundant_bits);
    uint32_t get_num_of_redundant_bits();
    uint32_t get_code_size();
};

class HammingDecoder
{
private:
    HammingCodeConfigurations configurations;
public:
    HammingDecoder(HammingCodeConfigurations configurations);
    ~HammingDecoder();
    uint32_t* decode(uint32_t* u_encoded_word, uint32_t u_size);
};


struct HammingCodeConfigurationsException : public std::exception {
   const char * what () const throw () {
      return "ERROR!!! u_num_of_redundant_bits > Max value allowed";
   }
};

#endif //__HAMMING_CODE_H__
