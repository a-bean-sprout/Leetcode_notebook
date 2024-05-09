/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:

    string longestPalindrome(string s) {
        // 参数检验
        if(s.empty()){
            return "";
        }

        // 思路：若判断dp[i][j]，则需根据dp[i+1][j-1]。也就是左下方需要先赋值。

        // 动态规划
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int maxLen = 0;
        int indexOfMaxLen = -1;
        for(int i = s.size() -1; i >= 0; --i){
            for(int j = i; j < s.size(); ++j){
                if(s[i] == s[j]){
                    if(j - i <= 1){
                        dp[i][j] = true;
                    }else if(dp[i+1][j-1]){
                        dp[i][j] = true;
                    }
                }

                // 存储结果
                if(dp[i][j] == true && maxLen < j - i + 1 ){
                    maxLen = j - i + 1;
                    indexOfMaxLen = i;
                }
            }
        }
        // 结果返回
        return s.substr(indexOfMaxLen, maxLen);
    }
};
// @lc code=end

// 笔记：
// 递推公式：dp[i][j] = dp[i+1][j-1]