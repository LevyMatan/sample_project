/**
 * @file trace.c
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief Enables indetations of traces: as we go depper in the function call stack, the more indenet the log will be.
 * @version 0.1
 * @date 2020-11-09
 *
 * @copyright Copyright (c) 2020
 *
 */

/*----------------------------------------------------------------
INCLUDES
----------------------------------------------------------------*/
#include "debug.h"


/*----------------------------------------------------------------
PRIVATE VARIABLES
----------------------------------------------------------------*/
static uint32_t g_num_of_tabs = 0; ///< Global used for identing the log files as we go inside a function.

/*----------------------------------------------------------------
EXTERNAL FUNCTIONS
----------------------------------------------------------------*/
/**
 * @brief Get the indent object
 *
 * @return uint32_t
 */
uint32_t get_indent(void)
{
    return g_num_of_tabs;
}

/**
 * @brief increase indent global variable
 *
 */
void increase_indent(void)
{
    g_num_of_tabs++;
}

/**
 * @brief decrease indent global variable
 *
 */
void decrease_indent(void)
{
    g_num_of_tabs--;
}

#ifdef DEBUG_PRINT_ON

void matan_wait(void)
{
    volatile uint32_t just_buying_time = 0;
    for (size_t i = 0; i < 3; i++)
    {
        just_buying_time = i;
        printf("The value of i is: %d\n", just_buying_time);
    }


}
/*----------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                              */
/*----------------------------------------------------------------*/
#else
void matan_wait(void){}

#endif /*DEBUG_PRINT_ON*/
