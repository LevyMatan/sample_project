#include "gtest/gtest.h"
#include "best_sum.h"
#include "vector.h"
#include "linked_list.h"
#include "debug.h"

TEST(BestSum, BaseCases) {

    DEBUG_PRINT("I am a debug print!!\n");
    std::cout << "Testing best_sum() with the following inputs:" << std::endl;
    // uint32_t a_target_num[] = {4, 5, 6, 8, 9, 12, 1098};
    uint32_t a_target_num[] = {19};
    uint32_t u_num_of_targets = sizeof(a_target_num) / sizeof(uint32_t);
    uint32_t a_array_of_nums[] = {5, 4, 3, 25};
    // uint32_t a_array_of_nums[] = {2 ,6, 10, 1, 14, 3, 5};
    uint32_t u_array_len = sizeof(a_array_of_nums) / sizeof(uint32_t);

    //  print array
    Node *p_root = NULL;
    // Loop over target nums
    for (uint32_t target_num_idx = 0; target_num_idx < u_num_of_targets; target_num_idx++)
    {
        std::cout << "how_sum(target_sum=" << a_target_num[target_num_idx] << ", ";
        std::cout << "[";
        for(uint32_t u_idx = 0; u_idx < (u_array_len - 1); u_idx++)
        {
            printf("%d, ", a_array_of_nums[u_idx]);
        }
        printf("%d", a_array_of_nums[u_array_len - 1]);
        std::cout << "]) -->" << std::endl;

        Vector *p_res_vec = best_sum(a_target_num[target_num_idx], a_array_of_nums, u_array_len, &p_root);
        vector_print(p_res_vec);
        std::cout << std::endl;
        if (p_res_vec)
        {
            vector_clear(p_res_vec);
        }
    }
}
