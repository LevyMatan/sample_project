#include "gtest/gtest.h"
#include "crc.h"

TEST(CRC, TestCRCForLetterM) {

    std::cout << "Testing crc() with the following inputs:" << std::endl;
    // uint32_t a_target_num[] = {4, 5, 6, 8, 9, 12, 1098};
    // uint16_t u_num = 'M';
    uint16_t u_num = 'B';

    std::cout << "Input: 0x" << std::hex << u_num << std::endl;
    uint16_t u_crc = crc16_ccitt(u_num);
    std::cout << "Expected Output: 0x" << std::hex << 0x6886 << std::endl;
    std::cout << "crc('B'): 0x" << u_crc << std::endl;

    EXPECT_EQ(0x6886, u_crc);
}
