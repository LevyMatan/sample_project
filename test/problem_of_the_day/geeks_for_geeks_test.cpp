#include "gtest/gtest.h"
#include "geeks_for_geeks.hpp"

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
    ASSERT_EQ(num_of_open_doors, 0);

}
