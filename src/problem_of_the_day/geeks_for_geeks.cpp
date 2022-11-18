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
#include "debug.h"

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
     * The above example was misleading! notice the input array is
     * soreted in acending order. Hence once we found the first element
     * strickly greater than K, all following element were as well.
     *
     * Lets look at another example
     * Arr = {5, 4, 6, 2} K = 4
     * Lets list all subarrays that start with a specific index.
     * ==> For index 0 are:
     * [5], [5, 4], [5, 4, 6], [5, 4, 6, 2]
     * Since Arr[0] is strickly greater than K=4, all sub-arrays
     * with this elements are counted.
     * ==> For index 1, all sub-arrays are:
     * [4], [4, 6], [4, 6, 2]
     * Since Arr[1] is not greater than K=4, **NOT** all sub-arrays
     * including it satisfy the condition. But once an element that is
     * strickly greater is added to the sub-array, all following are counted.
     * In this case, this element is in index 2, hence [4, 6], [4, 6, 2] are counted.
     * ==> For index 2, all subarrays are:
     * [6], [6, 2]
     * Again reapting the same logic, all subarrays are counted.
     * ==> For index 3, there is only a single subarray:
     * [2]
     * which is not counted.
     *
     * Now we can derive a nice easy algorithm:
     *
     * Initilize `result` to 0
     * For each __num__ in arr from end to begining:
     *
     *     if __num__ > k then:
     *          smallest_idx_greater_than_K <- idx(__num__)
     *     end if
     *
     *     // The number of all sub-arrays starting with element in idx
     *     // and including all elements that follow it, is the number of sub-arrays
     *     // that follow the first element including the one at idx that satisfy the
     *     // rule to be strickly greater than k.
     *
     *     add (length(arr)-smallest_idx_greater_than_K) to `result`;
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

/**
 * @brief Brute force implementation with debug prints to illustrae the state of doors
 *        each iteration.
 *        For info on the open doors question lookup on google.
 *        It is advised to use low values on n when in DEBUG mode since prints are added.
 *
 * @param n - number of doors in the corridor
 * @return int
 */
int GeeksForGeeksPOTD::count_open_doors_brute_force(int N)
{

    size_t n;
    if(N < 0)
    {
        return 0;
    }
    else
    {
        n = (size_t)N;
    }
    // Initialize a corridor array to represent each door state.
    // we assume the initiale state of all doors is open
    std::vector<bool> open_doors(n, true);

    // Debug print the doors index
    DEBUG_PRINT("%6s", "Step  ");
    for (size_t i = 0; i < n; i++)
    {
        DEBUG_PRINT("%4lu", (i+1));
    }
    DEBUG_PRINT("\n\n");

    // Iterate of steps sizes print the doors index
    for (size_t step = 1; step <= n; step++)
    {
        size_t door_idx = 0;
        while(door_idx < n)
        {
            // Toogle the door state: change close to open, and open to close
            open_doors[door_idx] = not open_doors[door_idx];

            // Go to next door at `step` distance
            door_idx += step;

        }

        // Debug Print
        DEBUG_PRINT("%-6lu", step);
        for (size_t i = 0; i < n; i++)
        {
            const char door_state = (open_doors[i]) ? ('O') : ('X');
            DEBUG_PRINT("%4c", door_state);
        }
        DEBUG_PRINT("\n");
    }

    return 0;
}
