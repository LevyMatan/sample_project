#include "construct.hpp"
#include <iostream>

static bool is_prefix(const std::string& target, const std::string& prefix)
{
    if (target.size() >= prefix.size())
    {
        return (target.compare(0, prefix.size(), prefix) == 0);
    }

    return false;
}

bool can_construct(std::string target, std::vector<std::string> a_word_bank, std::unordered_map<std::string, int>& memo)
{
    // std::cout << "Target: " << target << std::endl;
    // for (uint32_t i = 0; i < a_word_bank.size(); i++)
    // {
    //     std::cout << "Word: " << a_word_bank[i] << std::endl;
    // }

    if (memo.find(target) != memo.end())
    {
        return memo[target];
    }

    if (std::string("") == target)
    {
        return true;
    }

    bool found = false;

    for (uint32_t i = 0; i < a_word_bank.size(); i++)
    {
        if(is_prefix(target, a_word_bank[i]))
        {
            // std::cout << "Found prefix: " << a_word_bank[i] << std::endl;
            std::string new_target = target.substr(a_word_bank[i].size(), target.size());
            found |= can_construct(new_target, a_word_bank, memo);
        }
    }
    
    memo[target] = found;
    return found;

}


uint32_t count_construct(std::string target, std::vector<std::string> a_word_bank, std::unordered_map<std::string, int>& memo)
{
    if (memo.find(target) != memo.end())
    {
        // memo[target]++;
        return memo[target];
    }

    if (std::string("") == target)
    {
        return 1U;
    }

    uint32_t count = 0U;

    for (uint32_t i = 0; i < a_word_bank.size(); i++)
    {
        if(is_prefix(target, a_word_bank[i]))
        {
            // std::cout << "Found prefix: " << a_word_bank[i] << std::endl;
            std::string new_target = target.substr(a_word_bank[i].size(), target.size());
            count += count_construct(new_target, a_word_bank, memo);
        }
    }
    
    memo[target] = count;
    return count;
}
