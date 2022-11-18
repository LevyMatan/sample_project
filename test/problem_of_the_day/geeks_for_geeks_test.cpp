#include "gtest/gtest.h"
#include "geeks_for_geeks.hpp"
#include <random>
#include <debug.h>

TEST( ProblemOfTheDay, count_subarrays_test_random_array)
{

    int arr[] = {4, 5, 2, 132, 5425, 1, 55, 64};
    long long num_of_subarrays_greater_than_k = GeeksForGeeksPOTD::count_subarrays(arr, 8, 5);

    ASSERT_EQ(num_of_subarrays_greater_than_k, 29);

}

TEST( ProblemOfTheDay, count_subarrays_test_len_2)
{

    int arr[] = {4, 5};
    long long num_of_subarrays_greater_than_k = GeeksForGeeksPOTD::count_subarrays(arr, 2, 5);

    ASSERT_EQ(num_of_subarrays_greater_than_k, 0);

}


TEST( ProblemOfTheDay, count_open_doors_brute_force_8)
{

    int num_of_open_doors = GeeksForGeeksPOTD::count_open_doors_brute_force(8);
    ASSERT_EQ(num_of_open_doors, 2);

}

TEST( ProblemOfTheDay, count_open_doors_against_brute_force)
{

    #define MAX_N_DOORS (100)
    size_t num_of_test_cases = 20;
    for (size_t i = 0; i < num_of_test_cases; i++)
    {
        int N = random() % MAX_N_DOORS;
        DEBUG_PRINT("Testing for N = %d:\n", N);
        int num_of_open_doors_brute_force = GeeksForGeeksPOTD::count_open_doors_brute_force(N);
        int num_of_open_doors = GeeksForGeeksPOTD::count_open_doors(N);
        ASSERT_EQ(num_of_open_doors, num_of_open_doors_brute_force);
    }
}
TEST( ProblemOfTheDay, count_open_doors_against_best)
{

    #define MAX_N_DOORS_BEST (100000)
    size_t num_of_test_cases = 200;
    for (size_t i = 0; i < num_of_test_cases; i++)
    {
        int N = random() % MAX_N_DOORS_BEST;
        DEBUG_PRINT("Testing for N = %d:\n", N);
        int num_of_open_doors_best = GeeksForGeeksPOTD::count_open_doors_best(N);
        int num_of_open_doors = GeeksForGeeksPOTD::count_open_doors(N);
        ASSERT_EQ(num_of_open_doors, num_of_open_doors_best);
    }
}
