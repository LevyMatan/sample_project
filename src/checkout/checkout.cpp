#include "checkout.hpp" 

Checkout::Checkout():total(0)
{
    
}
Checkout::~Checkout()
{
    
}

void Checkout::addItemPrice(std::string item_name, int item_price)
{
    items_prices_list[item_name] = item_price;
}

void Checkout::addItem(std::string item_name)
{
    if (items_prices_list.find(item_name) == items_prices_list.end())
    {
        throw std::invalid_argument("Trying to add item which is not on the items price list!");
    }
    
    items[item_name]++;
}

void Checkout::addDiscount(std::string item_name, int number_of_items, int discount_price)
{
    Discount discount; 
    discount.discount_price = discount_price;
    discount.num_of_items = number_of_items;

    
    discounts[item_name] = discount;
    
}

int Checkout::calculateTotal(void)
{
    total = 0;
    std::map<std::string, int>::iterator item_itr;
    for(item_itr = items.begin(); item_itr != items.end(); ++item_itr)
    {
        total += calculateItem(item_itr);
    }
    return total;
}

/**
 * @brief 
 * 
 * @param[in] item_itr 
 * @return int 
 */
int Checkout::calculateItem(std::map<std::string, int>::iterator item_itr)
{
    int item_price;
    std::string item_name = item_itr->first;
    int item_count = item_itr->second;
    
    std::map<std::string, Discount>::iterator discount_itr;
    discount_itr = discounts.find(item_name);
    if(discount_itr != discounts.end())
    {
        Discount discount = discount_itr->second;
        item_price = (item_count / discount.num_of_items) * discount.discount_price + ((item_count % discount.num_of_items) * items_prices_list[item_name]);
    }
    else
    {
        item_price = item_count * items_prices_list[item_name];
    }
    
    return item_price;
}
