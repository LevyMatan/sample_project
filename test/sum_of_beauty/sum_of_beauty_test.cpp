#include "gtest/gtest.h"
#include "sum_of_beauty.hpp"
#include <bitset>

TEST( SumOfBeauty, SampleTestCase) {

  std::cout << "Testing sum_of_beauty()" << std::endl;
  std::cout << "Inputs:" << std::endl;
  std::string s("sdgnjsjklgnvjklsazdskjf");

  int sum_of_beauty = beautySum(s);

  ASSERT_EQ(sum_of_beauty, 232);

  // print_file_name();
}
