#include "gtest/gtest.h"
#include "grid_traveler.h"

#define LARGEST_FIBONACCI_NUMBER_TO_TEST (30)

TEST(GridTraveler, BaseCases) {

    std::cout << "Testing grid_traveler() for the first ten values:" << std::endl;
    for(uint32_t u_row = 1; u_row < 5; u_row++)
    {
        for( uint32_t u_col = 0; u_col < 5; u_col++ )
        {
            printf("grid_traveler(%2d, %2d) = %8d\n", u_row, u_col, grid_traveler(u_row, u_col, NULL));
        }
    }

}
