/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 参数检验
        if(s.empty()){
            return 0;
        }

        // 滑动窗口
        int left = 0, right = 0, max_result = 0;
        unordered_map<char, int> char_count_map;
        while(right < s.size()){
            char cur = s[right++];

            char_count_map[cur]++;

            while(char_count_map[cur] > 1){
                char drop_cur = s[left++];

                char_count_map[drop_cur]--;
            }

            max_result = max(max_result, right - left);
        }

        return max_result;
    }
};
// @lc code=end

