#include "gtest/gtest.h"
#include "checkout.hpp"

class CheckoutTest : public ::testing::Test {
  public:
  
  protected:
    Checkout checkOut;
  
};

TEST_F( CheckoutTest, CanCalculateTotal) {
  checkOut.addItemPrice("a", 1);
  checkOut.addItem("a");
  
  int total = checkOut.calculateTotal();
  ASSERT_EQ(1, total);
}

TEST_F( CheckoutTest, PrintInfo) {
  checkOut.addItemPrice("a", 1);
  checkOut.addItem("a");
  
  int total = checkOut.calculateTotal();
  std::cout << " The total is: " << total << std::endl;
  ASSERT_EQ(1, total);
}

TEST_F( CheckoutTest, CanGetTotalForMultipleItems) {
  checkOut.addItemPrice("a", 1);
  checkOut.addItemPrice("b", 1);
  checkOut.addItem("a");
  checkOut.addItem("b");
  
  int total = checkOut.calculateTotal();
  ASSERT_EQ(2, total);
}

TEST_F( CheckoutTest, CanAddDiscount) {
  checkOut.addDiscount("a", 3, 2);
}

TEST_F( CheckoutTest, CanCalculateTotalWithDiscount) {
  checkOut.addItemPrice("a", 1);
  checkOut.addDiscount("a", 3, 2);
  checkOut.addItem("a");
  checkOut.addItem("a");
  checkOut.addItem("a");


  int total = checkOut.calculateTotal();
  ASSERT_EQ(2, total);
}


TEST_F( CheckoutTest, ItemWithNoPriceThrowsException) {
  ASSERT_THROW(checkOut.addItem("a"), std::invalid_argument);
}
