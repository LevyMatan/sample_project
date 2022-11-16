/**
 * @file geeks_for_geeks.hpp
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief Here I will put all my solutions of the Geeks-For-Geeks Problem-Of-The-Day question.
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>

/**
 * @brief Geeks For Geeks Problem of the Day
 *
 */
class GeeksForGeeksPOTD
{
private:
    /* data */
public:
    GeeksForGeeksPOTD(/* args */);
    ~GeeksForGeeksPOTD();

    /**
     * @brief Given an array of N positive integers  Arr1, Arr2 ............ Arrn.
     *        The value of each contiguous subarray of given array is the maximum element present in that subarray.
     *        The task is to return the number of subarrays having value strictly greater than K.
     *
     * @param arr
     * @param n
     * @param k
     * @return long long
     */
    long long count_subarrays(int arr[], int n, int k);
};
