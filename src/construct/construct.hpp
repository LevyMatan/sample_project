/**
 * @file construct.h
 * @author Matan Levy (levymatanlevy@gmail.com)
 * @brief write a function "canConstruct(target, wordBank)" that accepets a target string and an array of strings.
 * @version 0.1
 * @date 2021-09-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <vector>
#include <unordered_map>

/**
 * @brief The function should return a boolean indicating whether or not the 'target' 
 *        can be constructed by concatenating elements of the 'wrodBank' array.
 * 
 *        It may reuse elements of 'wordBank' as many times as needed.
 * 
 *        Examples:
 *        can_construct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) --> true
 *        can_construct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) --> false
 *        can_construct("", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) --> true
 * 
 * 
 * @param target 
 * @param a_word_bank 
 * @return true 
 * @return false 
 */
bool can_construct(std::string target, std::vector<std::string> a_word_bank, std::unordered_map<std::string, int>& memo);

/**
 * @brief The function accepets a target string and an array of strings.
 *        The function should return the number of combinations of the 'wordBank' array that can be used to construct the 'target'.
 * 
 * @param target 
 * @param a_word_bank 
 * @param memo 
 * @return uint32_t 
 */
uint32_t count_construct(std::string target, std::vector<std::string> a_word_bank, std::unordered_map<std::string, int>& memo);

