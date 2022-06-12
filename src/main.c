#include <stdio.h>
#include "SampleProjectConfig.h"

void hello_not_used(void)
{
    printf("I am NOT used!!!\n");
}
void hello_used(void)
{
    printf("I am used!!!\n");
}

// int MyGlobalVarNotInitialized = 9;

int main(int argc, char *argv[])
{
    // report version
    printf("Running SampleProject Version %d.%d\n", SampleProject_VERSION_MAJOR, SampleProject_VERSION_MINOR);

    // print function input parameters
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    hello_used();



    return 0;
}
