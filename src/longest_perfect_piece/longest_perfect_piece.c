/**
 * @brief A Perfect Piece is defined as a subarray such that the difference between the minimum and the maximum value in that range is at most 1.
 *
 */

#include "longest_perfect_piece.h"
#include "debug.h"
/**
 * @brief Given an array arr[] of N Numbers. A Perfect Piece is defined as a subarray such that the difference between the minimum and the maximum value in that range is at most 1. Find the Maximal Length Perfect Piece.
 *
 * @method: Itertate through the array.
 *          Check the difference between two adajecent elements.
 *          If the difference absuolute value is greater than 1, this two element *can't* be in the same subarray.
 *          If the difference is 1, this element can be added to a continues subarray up to an element that differes by two
 * @param arr
 * @param N
 * @return int
 */
int longest_perfect_piece(int arr[], int N) {
    int a = 1;
    int b = 1;
    int c = 1;
    int res = 1;

    // char DEBUG_TITLE
    DEBUG_PRINT("INDEX| DIFF| A| B| C|\n");

    for(int i = 1; i < N; i++)
    {
        const int diff = arr[i] - arr[i-1];
        if(0 == diff)
        {
            a++;
            b++;
            c++;
        }
        else if(1 == diff)
        {
            b = c + 1;
            a = 1;
            c = 1;
        }
        else if(-1 == diff)
        {
            c = b + 1;
            a = 1;
            b = 1;
        }
        else
        {
            a = 1;
            b = 1;
            c = 1;
        }
        DEBUG_PRINT("%5d|%5d|%2d|%2d|%2d|\n", i, diff, a, b, c);

        if(res < a)
        {
            res = a;
        }
        if(res < b)
        {
            res = b;
        }
        if(res < c)
        {
            res = c;
        }

    }
    return res;
}
