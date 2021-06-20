#ifndef __PRINT_FILE_NAME_H__
#define __PRINT_FILE_NAME_H__

#include <stdint.h>
#include <stdio.h>


#ifdef __cplusplus 
extern "C" {
#endif // __cplusplus 
    
void print_file_name(void)
{
    printf("Writing from file: %s\n", __FILE__);
}

#ifdef __cplusplus 
}
#endif // __cplusplus 

#endif //__PRINT_FILE_NAME_H__
