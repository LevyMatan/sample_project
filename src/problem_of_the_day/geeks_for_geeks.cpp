/**
 * @file geeks_for_geeks.cpp
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "geeks_for_geeks.hpp"
#include <iostream>
#include <vector>
#include <limits.h>

GeeksForGeeksPOTD::GeeksForGeeksPOTD(/* args */)
{
}

GeeksForGeeksPOTD::~GeeksForGeeksPOTD()
{
}


/**
 * @brief Given an array of N positive integers  Arr1, Arr2 ............ Arrn.
 *        The value of each contiguous subarray of given array is the maximum element present in that subarray.
 *        The task is to return the number of subarrays having value strictly greater than K.
 *        Example 1:

        Input:
            N = 3, K = 2
            Arr[] = {3, 2, 1}
        Output: 3
            Explanation: The subarrays having value
            strictly greater than K are: [3], [3, 2]
            and [3, 2, 1]. Thus there are 3 such
            subarrays.
            Example 2:

        Input:
            N = 4, K = 1
            Arr[] = {1, 2, 3, 4}
        Output: 9
            Explanation: There are 9 subarrays having
            value strictly greater than K.
 *
 * @param arr
 * @param n
 * @param k
 * @return long long
 */
long long GeeksForGeeksPOTD::count_subarrays(int arr[], int n, int k)
{
    /**
     * @brief First let us compute a an example manually:
     * Arr = {1, 2, 3, 4}, K = 1
     * Note: counting all sub-arrays take N**2 operations.
     * I will start from the first element
     * First sub-array is [1]                                : 0
     * which doesn't qualify as strickly greater than K=1    :
     * Second sub-array is [1, 2]                            : 1
     * Which does qualify as valid sub-array                 :
     * From there [1, 2, 3] and [1, 2 ,3 ,4]                 : 2
     * Now next step is moving left window limit by one      :
     * First sub-array is [2] which does qualify             : 1
     * Than all other qualify as well: [2, 3], [2, 3, 4]     : 2
     * Same will happen on [3], [3, 4]                       : 2
     * Same will happen on [4]                               : 1
     * Total will be 0 + 1 + 2 + 1 + 2 + 2 + 1 = 9
     *
     * After taking a look at the example
     * One can deduce an algorithm.
     * For each __num__ in arr:
     *     if __num__ > k then:
     *          add length(arr)-idx(__num__)
     *
     */

    long long count_subarrays = 0;
    int last_idx = n;
    for(int idx = n-1; idx >= 0; idx--)
    {
        if(arr[idx] > k)
        {
            last_idx = idx;
        }
        count_subarrays += (n - last_idx);
    }

    return count_subarrays;
}