#include <iostream>
#include "get_rx_tx_mask.h"
#include "SampleProjectConfig.h"

int main(int argc, char *argv[])
{

    // report version
    std::cout << "Running SampleProject Version" << SampleProject_VERSION_MAJOR << "."
              << SampleProject_VERSION_MINOR << std::endl;
    
	std::cout << "Program was invoked by: " << std::endl;
	for (int arg_idx = 0; arg_idx < argc; arg_idx++)
	{
		std::cout << argv[arg_idx] << std::endl;
	}
    
        // std::cout << "Usage: " << argv[0] << " number" << std::endl;
    
    
    
    
    return 0;
}
