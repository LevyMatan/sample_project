#include <iostream>
#include <iomanip>
#include <bitset>
#include "get_rx_tx_mask.h"
#include "SampleProjectConfig.h"

int main(int argc, char *argv[])
{

    // report version
    std::cout << "Running SampleProject Version " << SampleProject_VERSION_MAJOR << "."
              << SampleProject_VERSION_MINOR << std::endl;
    
	std::cout << "Program was invoked by: " << std::endl;
	for (int arg_idx = 0; arg_idx < argc; arg_idx++)
	{
		std::cout << argv[arg_idx] << std::endl;
	}
    
    
    
    std::cout << "Please enter how many bits to mask:" << std::endl;
    int64_t bits_to_mask = 0;
    std::cin >> bits_to_mask;
    
    int rx_tx_mask = BITMASK_OF_LENGTH(bits_to_mask);
    
    std::cout << "Hex Mask: = 0x" 
              << std::hex 
              << std::uppercase 
              << std::setfill('0')
              << std::setw(8)
              << rx_tx_mask << std::endl;

    std::cout << "Binary Mask: = b" 
              << std::uppercase 
              << std::setfill('0')
              << std::setw(32)
              << std::bitset<32>(rx_tx_mask) << std::endl;
    
    
    return 0;
}
