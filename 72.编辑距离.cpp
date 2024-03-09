/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 参数检验
        
        // 动态规划
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

        // 初始化
        for(int i = 0; i < word1.size()+1; ++i) dp[i][0] = i;
        for(int j = 0; j < word2.size()+1; ++j) dp[0][j] = j;

        for(int i = 1; i < word1.size()+1; ++i){
            for(int j = 1; j < word2.size()+1; ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1]; 
                }else{
                    dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i][j-1]+1, dp[i-1][j]+1));
                }
            }
        }

        // 返回
        return dp.back().back();
    }
};
// @lc code=end

// 思路：编辑距离，增删改三种操作，使两个字符串相等

// dp[i][j]
// 1. s[i-1] == t[j-1], dp[i][j] = dp[i-1][j-1]
// 2. s[i-1] != t[j-1], 增：dp[i-1][j]+1, dp[i][j-1]+1, 改：dp[i-1][j-1]+1

