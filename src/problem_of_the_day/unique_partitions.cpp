/**
 * @file unique_partitions.cpp
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief Given a positive integer n, generate all possible unique ways to represent n as sum of positive integers.
 *        Note: The generated output is printed without partitions.
 *        Each partition must be in decreasing order. Printing of all the partitions is done in reverse sorted order.
 *
 *        Example 1:
 *
 *        Input: n = 3
 *        Output: 3 2 1 1 1 1
 *        Explanation: For n = 3,
 *        {3}, {2, 1} and {1, 1, 1}.
 *
 *
 *        Example 2:
 *
 *        Input: n = 4
 *        Output: 4 3 1 2 2 2 1 1 1 1 1 1
 *        Explanation: For n = 4,
 *        {4}, {3, 1}, {2, 2}, {2, 1, 1}, {1, 1, 1, 1}.
 *
 * @version 0.1
 * @date 2022-11-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <vector>
#include <map>

std::vector<std::vector<int>> UniquePartitionsRec(int n, std::map<int,std::vector<std::vector<int>>*> &memo)
{
    if(memo.find(n) == memo.end())
    {
        memo[n] = new std::vector<std::vector<int>>(1, std::vector<int>(1, n));

        int lower = 0;
        int bigger = n;

        while((lower < n) && (n > 1))
        {
            lower++;
            bigger = n - lower;
            std::vector<std::vector<int>> lower_partitions = UniquePartitionsRec(lower, memo);
            for(auto lower_partition:lower_partitions)
            {
                if(lower_partition[0] <= bigger)
                {
                    std::vector<int> *p_partition = new std::vector<int>(1, bigger);
                    for(auto num:lower_partition)
                    {
                        (*p_partition).push_back(num);
                    }

                    (*memo[n]).push_back((*p_partition));

                }
            }

        }
    }

    return (*memo[n]);
}

std::vector<std::vector<int>> UniquePartitions(int n) {
    std::map<int,std::vector<std::vector<int>>*> memo;

    return UniquePartitionsRec(n, memo);
}