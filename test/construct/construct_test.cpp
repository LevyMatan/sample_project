#include "gtest/gtest.h"
#include "construct.hpp"

TEST(Construct, canConstruct) {

    std::unordered_map<std::string, int> memo;
    std::string target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
    std::vector<std::string> wordBank = {std::string("e"), std::string("eeee"), std::string("eeeeeeeeeeeeeee"), std::string("eee"), std::string("o")};
    // std::string target = "Hello";
    // std::vector<std::string> wordBank = {std::string("H"), std::string("Hel"), std::string("bye"), std::string("l"), std::string("o")};
    std::cout << can_construct(target, wordBank, memo) << std::endl;
}

TEST(Construct, countConstruct) {

    std::unordered_map<std::string, int> memo;
    std::string target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    std::vector<std::string> wordBank = {std::string("e"), std::string("eeee"), std::string("eeeeeeeeeeeeeee"), std::string("eee"), std::string("o")};
    // std::string target = "Hello";
    // std::vector<std::string> wordBank = {std::string("H"), std::string("He"), std::string("Hell"), std::string("Hel"), std::string("bye"), std::string("l"), std::string("o")};
    // std::string target = "purple";
    // std::vector<std::string> wordBank = {std::string("purp"), std::string("p"), std::string("ur"), std::string("le"), std::string("purpl")};
    // std::string target = "enterapotentpot";
    // std::vector<std::string> wordBank = {std::string("a"), std::string("p"), std::string("ent"), std::string("enter"), std::string("ot"), std::string("o"), std::string("t")};
    std::cout << count_construct(target, wordBank, memo) << std::endl;

    std::cout << "memo size: " << memo.size() << std::endl;
    std::cout << "memo: " << std::endl;

    for (auto it = memo.begin(); it != memo.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}
