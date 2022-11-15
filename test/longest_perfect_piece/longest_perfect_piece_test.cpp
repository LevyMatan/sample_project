#include "gtest/gtest.h"
#include "longest_perfect_piece.h"


TEST(LongestPerfectPiece, BaseCases) {

    std::cout << "Testing LongestPerfectPiece() with the following inputs:" << std::endl;
    int a_array_of_nums[] = {5, 4, 5, 5, 6, 7, 8, 8, 8, 7};

    //  print array
    const int res = longest_perfect_piece(a_array_of_nums, 10);
    ASSERT_EQ(res, 5);
}
