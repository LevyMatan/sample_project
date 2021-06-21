#include <stdio.h>
// #include "get_rx_tx_mask.h"
// #include "SampleProjectConfig.h"

void hello_not_used(void)
{
    printf("I am NOT used!!!\n");
}
void hello_used(void)
{
    printf("I am used!!!\n");
}


int main(int argc, char *argv[])
{

    // report version
    // std::cout << "Running SampleProject Version" << SampleProject_VERSION_MAJOR << "."
    //           << SampleProject_VERSION_MINOR << std::endl;
    
    
    // std::cout << "Usage: " << argv[0] << " number" << std::endl;
    hello_used();
    
    
    
    return 0;
}
