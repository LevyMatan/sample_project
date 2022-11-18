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
#include <algorithm>
#include <vector>
#include <limits.h>
#include "reverse_spiral.hpp"
#include <math.h>
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
    std::vector<bool> open_doors(n, false);

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
        size_t door_idx = (step-1);
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

    return std::count(open_doors.begin(), open_doors.end(), true);
}



/**
 * @brief Consider a long alley with a N number of doors on one side.
 * All the doors are closed initially. You move to and forward in the alley
 * changing the states of the doors as follows: you open a door that is
 * already closed and you close a door that is already opened.
 * You start at one end go on altering the state of the doors
 * till you reach the other end and then you come back and start
 * altering the states of the doors again.
 * In the first go, you alter the states of doors numbered 1, 2, 3, , n.
 * In the second go, you alter the states of doors numbered 2, 4, 6
 * In the third go, you alter the states of doors numbered 3, 6, 9
 * You continue this till the Nth go in which you alter the state of the door numbered N.
 * You have to find the number of open doors at the end of the procedure.
 *
 */
int GeeksForGeeksPOTD::count_open_doors(int N)
{
    /**
     * @brief Let us look at an example of itertaitng
     *  Map: O - Door is open, X - Door is close
     *  Step     1   2   3   4   5   6   7   8
     *
     *  1        O   O   O   O   O   O   O   O
     *  2        O   X   O   X   O   X   O   X
     *  3        O   X   X   X   O   O   O   X
     *  4        O   X   X   O   O   O   O   O
     *  5        O   X   X   O   X   O   O   O
     *  6        O   X   X   O   X   X   O   O
     *  7        O   X   X   O   X   X   X   O
     *  8        O   X   X   O   X   X   X   X
     * Lets think how many times we visit each door:
     * Door 1 is visited a single time ==> will remain open.
     * Door 2: is visited twice ==> will remain closed.
     * Door 3: is visited twice ==> will remain closed.
     * Door 4: is visited three times[1, 2, 4] ==> will remain open.
     * Door 5: is visited twice [1, 5] ==> will remain closed.
     * Door 6: is visited four times [1, 2, 3, 6] ==> remains closed.
     *
     * Understand which doors will be visited Odd or Even times.
     * All doors that are visited Odd number of times will be open at the end.
     * It is essentianlly boils to the question, how many factors a number have.
     * Each number has at least two: 1 and itself.
     * Which numbers have an Odd number of factors?
     * Lets take a look at a random number X
     * let us try and define its factors
     * X = 1 * X
     * X = a * b
     * we know that a,b < X.
     * Hence if a != b, for each number X the factors comes in pairs
     * that is, an Even number of factors.
     * In the case where X = a * a, X had an Odd number of factors.
     *
     * Ok! now we have a plan.
     * To answer the question we can solve a different one,
     * How many numbers in the range of [1, N] have a sqaure root in the natural numbers field
     * 1 = 1 * 1
     * 4 = 2 * 2
     * 9 = 3 * 3
     * 16 = 4 * 4
     * 25 = 5 * 5
     * 36 = 6 * 6
     *
     *
     */

    int res = 0;
    int i = 1;
    while(i*i <= N)
    {
        res++;
        i++;
    }

    return res;

}

int GeeksForGeeksPOTD::count_open_doors_best(int N)
{
    /**
     * @brief Continuing the logic of count_open_doors
     * the count is actuall floor(sqrt(N))
     *
     */

    return floor(sqrt(N));
}


std::vector<int> GeeksForGeeksPOTD::reverseSpiral(int R, int C, std::vector<std::vector<int>>&a)
{
    std::vector<int> reverse_spiral(R*C);
    std::vector<std::vector<bool>> not_visited(R, std::vector<bool>(C,true));
    int num_of_rows = C;
    int num_of_cols = R;
    int row_idx = 0;
    int col_idx = 0;
    ReverseSpiral::direction_e e_direction = ReverseSpiral::direction_e::RIGHT_E;

    DEBUG_PRINT("Staring with a matrix of size %d X %d which means:\n", R,C);
    DEBUG_PRINT("The length of a colum is %d\n", num_of_rows);
    DEBUG_PRINT("The length of a row is %d\n", num_of_cols);
    for(int idx = 0; idx < R*C; idx++)
    {
        reverse_spiral[R*C-1-idx] = a[row_idx][col_idx];
        not_visited[row_idx][col_idx] = false;

        if(!ReverseSpiral::can_go_forward(e_direction, row_idx, num_of_cols, col_idx, num_of_rows, not_visited))
        {
            e_direction = ReverseSpiral::next_direction(e_direction);
        }

        ReverseSpiral::move_forward(e_direction, row_idx, col_idx);
    }

    return reverse_spiral;
}

bool ReverseSpiral::can_go_forward(ReverseSpiral::direction_e e_direction, int row_idx, int row_len, int col_idx, int col_len, std::vector<std::vector<bool>> &not_visited)
{
    bool can_go = false;
    int next_row_idx = row_idx;
    int next_col_idx = col_idx;
    DEBUG_PRINT("can_go_forward? to directing=%d, row_idx=%d, row_len=%d, col_idx=%d, col_len=%d == ",e_direction, row_idx, row_len, col_idx, col_len);
    switch(e_direction)
    {
        case ReverseSpiral::direction_e::RIGHT_E:
            next_col_idx++;
            if((next_col_idx < col_len) && (not_visited[next_row_idx][next_col_idx]))
            {
                can_go = true;
            }
            break;
        case ReverseSpiral::direction_e::DOWN_E:
            next_row_idx++;
            if((next_row_idx < row_len) && (not_visited[next_row_idx][next_col_idx]))
            {
                can_go = true;
            }
            break;
        case ReverseSpiral::direction_e::LEFT_E:
            next_col_idx--;
            if((next_col_idx >= 0) && (not_visited[next_row_idx][next_col_idx]))
            {
                can_go = true;
            }
            break;
        case ReverseSpiral::direction_e::UP_E:
            next_row_idx--;
            if((next_row_idx >= 0) && (not_visited[next_row_idx][next_col_idx]))
            {
                can_go = true;
            }
            break;
        default:
            break;
    }
    if(can_go)
    {
        DEBUG_PRINT("YES\n");
    }
    else
    {
        DEBUG_PRINT("NO\n");
    }

    return can_go;
}

void ReverseSpiral::move_forward(ReverseSpiral::direction_e e_direction, int &row_idx, int &col_idx)
{
    switch(e_direction)
    {
        case ReverseSpiral::direction_e::RIGHT_E:
            col_idx++;
            break;
        case ReverseSpiral::direction_e::DOWN_E:
            row_idx++;
            break;
        case ReverseSpiral::direction_e::LEFT_E:
            col_idx--;
            break;
        case ReverseSpiral::direction_e::UP_E:
            row_idx--;
            break;
        default:
            break;
    }
}

ReverseSpiral::direction_e ReverseSpiral::next_direction(ReverseSpiral::direction_e e_direction)
{
    DEBUG_PRINT("Next direction: ");
    ReverseSpiral::direction_e new_dir = ReverseSpiral::get_next_direction(e_direction);
    switch(new_dir)
    {
        case ReverseSpiral::direction_e::RIGHT_E:
            DEBUG_PRINT("RIGHT!\n");
            break;
        case ReverseSpiral::direction_e::DOWN_E:
        DEBUG_PRINT("DOWN!\n");

            break;
        case ReverseSpiral::direction_e::LEFT_E:
        DEBUG_PRINT("LEFT!\n");

            break;
        case ReverseSpiral::direction_e::UP_E:
        DEBUG_PRINT("UP!\n");
            break;
        default:
        break;

    }
    return new_dir;
}

ReverseSpiral::direction_e ReverseSpiral::get_next_direction(ReverseSpiral::direction_e e_direction)
{
    return (ReverseSpiral::direction_e)(((int)(e_direction) + 1) % 4);
}
