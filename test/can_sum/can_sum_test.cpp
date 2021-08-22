#include "gtest/gtest.h"
#include "can_sum.h"

TEST(CanSum, BaseCases) {

    std::cout << "Testing can_sum() with the following inputs:" << std::endl;
    uint32_t a_target_num[] = {4, 5, 6, 8, 9, 12, 1098};
    uint32_t u_num_of_targets = sizeof(a_target_num) / sizeof(uint32_t);
    uint32_t a_array_of_nums[] = {2 ,6, 10, 1, 14, 3, 5};
    uint32_t u_array_len = sizeof(a_array_of_nums) / sizeof(uint32_t);

    //  print array
    std::cout << "Array: [";
    for(uint32_t u_idx = 1; u_idx < u_array_len; u_idx++)
    {
        printf("%4d, ", a_array_of_nums[u_idx]);
    }
    std::cout << "];" << std::endl;

    // Loop over target nums
    for (uint32_t target_num_idx = 0; target_num_idx < u_num_of_targets; target_num_idx++)
    {
        std::cout << "For target of " << a_target_num[target_num_idx] << ", ";
        if (can_sum(a_target_num[target_num_idx], a_array_of_nums, u_array_len))
        {
            std::cout << "there is a combination of numbers that sums up for the target" << std::endl;
        }
        else
        {
            std::cout << "there is NO combination of numbers that sums up for the target" << std::endl;
        }
    }
}
