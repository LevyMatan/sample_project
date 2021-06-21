#ifndef CHECKOUT_H
#define CHECKOUT_H
 
#include <string>
#include <map>

class Checkout
{
private:

 
public:
    Checkout();
    virtual ~Checkout();
    void addItemPrice(std::string item_name, int item_price);
    void addItem(std::string item_name);
    void addDiscount(std::string item_name, int number_of_items, int discount_price);
    int calculateTotal(void);
    int calculateItem(std::map<std::string, int>::iterator item_itr);
    
protected:
    struct Discount{
        int num_of_items;
        int discount_price;
    };
    std::map<std::string, int> items_prices_list;
    
    std::map<std::string, Discount> discounts;
    std::map<std::string, int> items;
    int total;
};
 
#endif // CHECKOUT_H
