/**
 * @file magic_triplets.cpp
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief Magic Triplets
 * @version 0.1
 * @date 2022-11-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <vector>

/**
 * @brief Given an array of size n, a triplet (a[i], a[j], a[k]) is called a Magic Triplet if a[i] < a[j] < a[k] and i < j < k.
 *        Count the number of magic triplets in a given array.
 *
 *        Example 1:
 *
 *        Input: arr = [3, 2, 1]
 *        Output: 0
 *        Explanation: There is no magic triplet.
 *
 *        Example 2:
 *
 *        Input: arr = [1, 2, 3, 4]
 *        Output: 4
 *        Explanation: Fours magic triplets are
 *        (1, 2, 3), (1, 2, 4), (1, 3, 4) and
 *        (2, 3, 4).
 *
 * @return int
 */
int countTriplets(std::vector<int>nums)
{
    if(nums.size() < 3)
    {
        return 0;
    }
    int counter = 0;
    for(int j = 1; j < nums.size()-1; j++)
    {
        int a_j = nums[j];

        int count_lower = 0;

        for(int i = j-1; i >= 0; i--)
        {
            int a_i = nums[i];

            if(a_j > a_i)
            {
                count_lower++;
            }
        }
        int count_higher = 0;
        for(int k = j+1; k < nums.size(); k++)
        {
            int a_k = nums[k];
            if(a_k > a_j)
            {
                count_higher++;
            }
        }

        counter += (count_higher * count_lower);
    }

    return counter;
}