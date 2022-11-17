
/*----------------------------------------------------------------
EXTERNAL INCLUDES
----------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>

#include <string.h>
#include <stdlib.h>

/*----------------------------------------------------------------
PRIVATE INCLUDES
----------------------------------------------------------------*/
#define SINGLE_THREAD_DEBUG_MODE_ON

/*----------------------------------------------------------------
EXTERNAL DEFINES
----------------------------------------------------------------*/
#define RED__CONSOLE_COLOR_CODE                               (12)
#define GREEN__CONSOLE_COLOR_CODE                             (10)
#define WHITE__CONSOLE_COLOR_CODE                             (15)
#define MAGENTA__CONSOLE_COLOR_CODE                           (13)
#define YELLOW__CONSOLE_COLOR_CODE                            (14)
#define BLUISH__CONSOLE_COLOR_CODE                            (11)

/*----------------------------------------------------------------
DEBUG AND TEST NOBS
----------------------------------------------------------------*/
#define DEBUG_PRINT_COLORS_OFF          ///< To enable color changes of console prits
#define SINGLE_THREAD_DEBUG_MODE_OFF    ///< Since the trace implementation uses globals, which I don't want to protect with locks as it might change the program flow, we will disable the use of identitaion in when not in single thread mode.
/*----------------------------------------------------------------
MACROS
----------------------------------------------------------------*/
#define print_error_msg(...)                                                    \
        {                                                                       \
            HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);            \
            SetConsoleTextAttribute(console_handle, RED__CONSOLE_COLOR_CODE);   \
            printf("ERROR!  File: %s, Line: %d\n", __FILE__, __LINE__);         \
            printf("ERROR!  Msg : ");                                           \
            printf(__VA_ARGS__);                                                \
            SetConsoleTextAttribute(console_handle, WHITE__CONSOLE_COLOR_CODE); \
        }
// Debug Levels
/**
 * @brief Debug Levels
 * Description: To enable debug printing, with easier toggle on/off of specific verbosity levels.
 *              Each DEBUG_PRINT statment will be assosicated with a specific verbosity level.
 *              A global DEBUG_VERBOSITY_LEVEL will define how many prints of logs we wish to see.
 *              The higher it is define, the more prints should be shown.
 *              To fully utilize this mechanism, each print statement should think out the how needed are those prints.
 *              For example, DEBUG_PRINT_FUNCTION_START() assigns level one, because it is useally usefull to have a function
 *              start and end prints - lets you know a specific function was called and executed.
 *              As a rule of thumb, if the print statment is located in a "deep" or long loops, it is wise to assign
 *              a larger debug level, so it will show up on when needed to avoid clutter.
 *
 */
#define DEBUG_VERBOSITY_LEVEL                                           (5)

#define DEBUG_LEVEL_LOWEST                                              (0)
#define DEBUG_LEVEL_ONE                                                 (1)
#define DEBUG_LEVEL_TWO                                                 (2)
#define DEBUG_LEVEL_THREE                                               (3)
#define DEBUG_LEVEL_FOUR                                                (4)
#define DEBUG_LEVEL_FIVE                                                (5)
#define DEBUG_LEVEL_SIX                                                 (6)
#define DEBUG_LEVEL_SEVEN                                               (7)
#define DEBUG_LEVEL_EIGHT                                               (8)
#define DEBUG_LEVEL_NINE                                                (9)
#define DEBUG_LEVEL_HIGHEST                                             (10)

#ifdef DEBUG_PRINT_ON

#define MAX_LOG_FUNCTION_LINE                                           (80)
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
/**
 * @brief Get the indent object
 *
 * @return uint32_t
 */
uint32_t get_indent(void);

/**
 * @brief increase indent global variable
 *
 */
void increase_indent(void);

/**
 * @brief decrease indent global variable
 *
 */
void decrease_indent(void);
#ifdef __cplusplus
}
#endif // __cplusplus
#ifdef SINGLE_THREAD_DEBUG_MODE_ON

#define GET_INDENT()          get_indent()
#define INCREASE_INDENT()     increase_indent()
#define DECREASE_INDENT()     decrease_indent()

#else

#define GET_INDENT()          (0)
#define INCREASE_INDENT()
#define DECREASE_INDENT()

#endif /*SINGLE_THREAD_DEBUG_MODE_ON*/

#define DEBUG_PRINT(...)                                      \
        {                                                                    \
            const uint32_t indent = GET_INDENT();                               \
            for(uint32_t indent_idx = 0; indent_idx < indent; indent_idx++)     \
            {                                                                \
                printf("----"); \
            }                                                                \
            printf(__VA_ARGS__);                                         \
        }
#define DEBUG_PRINT_NO_IDENT(...) printf(__VA_ARGS__)

#define DEBUG_PRINT_IDENT_ONLY()    \
{                                   \
            const uint32_t indent = GET_INDENT();                               \
            for(uint32_t indent_idx = 0; indent_idx < indent; indent_idx++)     \
            {                                                                \
                printf("----"); \
            }                                                                \
}

#define DEBUG_PRINT_ARG(...)                                                 \
        {                                                                    \
            DEBUG_PRINT("Input Arguments:\n" );             \
            DEBUG_PRINT(__VA_ARGS__ );                      \
        }

#define DEBUG_PRINT_FUNCTION_START()                                         \
        {                                                                    \
            DEBUG_PRINT("START: %s\n", __FUNCTION__);                        \
            INCREASE_INDENT();                                               \
        }

#define DEBUG_PRINT_FUNCTION_END()                                           \
        {                                                                    \
            DECREASE_INDENT();                                               \
            DEBUG_PRINT("END: %s\n", __FUNCTION__ );                       \
        }


#else

#define DEBUG_PRINT(...)
#define DEBUG_PRINT_NO_IDENT(...)
#define DEBUG_PRINT_IDENT_ONLY()
#define DEBUG_PRINT_ARG(...)
#define DEBUG_PRINT_FUNCTION_START()
#define DEBUG_PRINT_FUNCTION_END()

#endif /* DEBUG_PRINT_ON */

    #ifdef DEBUG_PRINT_ON
    #define DEBUG_PRINT_VECTOR(p_vec) vector_print(p_vec);
    #define DEBUG_PRINT_LIST(p_vec) list_print(p_vec);

    #else
    #define DEBUG_PRINT_VECTOR(p_vec)
    #define DEBUG_PRINT_LIST(p_vec)
    #endif

    void matan_wait(void);
