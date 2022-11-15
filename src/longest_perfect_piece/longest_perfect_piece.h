#ifndef __LONGEST_PERFECT_PIECE_H__
#define __LONGEST_PERFECT_PIECE_H__
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
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
int longest_perfect_piece(int arr[], int N);

#ifdef __cplusplus
}
#endif // __cplusplus