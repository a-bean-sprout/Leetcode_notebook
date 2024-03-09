/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 参数检验
        if(text1.empty() || text2.empty()){
            return 0;
        }

        // 动态规划
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));

        for(int i = 1; i < dp.size(); ++i){
            for(int j = 1; j < dp[0].size(); ++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // 返回
        return dp.back().back();
    }
};
// @lc code=end

// 最长公共子序列
// 思路是动态规划
// dp[i][j]：str中第i个元素及之前，最长公共子序列。对应索引[0~i-1]
// dp[i][j] = dp[i-1][j-1] + 1 if ==
//          = max(dp[i][j-1], dp[i-1][j])
// 思路：其实可以理解为有三个方向过来，注意理解。


