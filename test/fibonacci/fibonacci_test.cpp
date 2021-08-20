#include "gtest/gtest.h"
#include "fibonacci.h"

#define LARGEST_FIBONACCI_NUMBER_TO_TEST (30)

TEST(Fibonacci, BaseCases) {

    std::cout << "Testing fib() for the first ten values:" << std::endl;
    for(uint32_t u_fib_num = 1; u_fib_num < LARGEST_FIBONACCI_NUMBER_TO_TEST; u_fib_num++)
    {
        printf("fib(%2d) = %8d\n", u_fib_num, fib(u_fib_num));
    }

}
