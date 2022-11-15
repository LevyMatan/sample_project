/**
 * @brief
 *
 */

#include <string>
#include <vector>
#include <limits.h>
/**
 * @brief
 *
 * @param s
 * @return int
 */
int beautySum(std::string s)
{
    // Sounds like a Dynamic Programing question
    // We will iterate over all subarrays


    int beauty_sum = 0;
    for(unsigned long left_idx = 0; left_idx < s.size(); left_idx++)
    {
        std::vector<int> chars_count(26,0);
        int max_count = 0;
        int beauty;
        for(unsigned long right_idx = left_idx; right_idx < s.size(); right_idx++)
        {
            int min_count = INT_MAX;
            const char ch = s[right_idx];
            const int ch_idx = ch - 'a';
            chars_count[ch_idx]++;

            // update counts
            max_count = (max_count > chars_count[ch_idx]) ? (max_count) : (chars_count[ch_idx]);
            for(int count:chars_count)
            {
                if((count > 0) && (count < min_count))
                min_count = count;
            }
            beauty = max_count - min_count;
            beauty_sum += beauty;
        }
    }
    return beauty_sum;
}