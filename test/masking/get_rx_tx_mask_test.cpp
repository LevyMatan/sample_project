#include "gtest/gtest.h"
#include "get_rx_tx_mask.h"

TEST( GetRxTxMask, SampleTestCase) {
  
  std::cout << "Testing get_rx_tx_mask()" << std::endl;
  std::cout << "Inputs:" << std::endl;
  uint32_t a_rx_tx_mask_array[4] = {0xFFFF, 0x0, 0x0, 0xFFFF};
  const int payload_index = 90;
  const int number_of_payloads = 9;
  for(uint32_t i = 0; i < 4; i++)
  {
      std::cout << "a_rx_tx_mask_array[" << i << "]: " << std::bitset<32>(a_rx_tx_mask_array[i]) << std::endl;
  }
  std::cout << "payload_index        : " << payload_index << std::endl;
  std::cout << "number_of_payloads   : " << number_of_payloads << std::endl;
  uint32_t mask = get_rx_tx_mask(a_rx_tx_mask_array, payload_index, number_of_payloads);
  std::cout << "Outputs              : " << std::endl;
  std::cout << "Mask                 : " << std::bitset<32>(mask) << std::endl;
  ASSERT_EQ(mask, 0b00000000000000000000000111000000);
  
  // print_file_name();
}
