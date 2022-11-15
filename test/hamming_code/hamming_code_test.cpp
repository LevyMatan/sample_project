#include "gtest/gtest.h"
#include "hamming_code.hpp"

TEST(HAMMING_CODE, TestHammingCodeConfigurationsInitNotValid) {

    uint32_t u_num_of_redundant_bits = 15;
    // HammingCodeConfigurations configs(u_num_of_redundant_bits);
    // Catch the exception throwen in constructor
    ASSERT_THROW(HammingCodeConfigurations configs(u_num_of_redundant_bits), HammingCodeConfigurationsException);
}

TEST(HAMMING_CODE, TestHammingCodeConfigurationsInitValid) {

    uint32_t u_num_of_redundant_bits = 5;
    HammingCodeConfigurations configs(u_num_of_redundant_bits);

    // Verify the values of the configuration
    ASSERT_EQ(configs.get_num_of_redundant_bits(), u_num_of_redundant_bits);
    ASSERT_EQ(configs.get_code_size(), (1U << u_num_of_redundant_bits));
}

// TEST(HAMMING_CODE, TestHammingCodeConfigurationsInitValid) {

//     uint32_t u_num_of_redundant_bits = 5;
//     HammingCodeConfigurations configs(u_num_of_redundant_bits);

//     // Verify the values of the configuration
//     ASSERT_EQ(configs.get_num_of_redundant_bits(), u_num_of_redundant_bits);
//     ASSERT_EQ(configs.get_code_size(), (1U << u_num_of_redundant_bits));
// }
