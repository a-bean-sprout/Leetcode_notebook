/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 参数检验
        if(coins.empty() || amount < 0){
            return -1;
        }

        // 构建DP数组 & 确定下标含义
        vector<int> dp(amount+1, amount+1);
        
         // 初始化
        dp[0] = 0;

        // 递归公式
        // dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]]+1)
        // dp[j] = min(dp[j], dp[j-coins[i]]+1)
        for(int i = 0 ; i < coins.size(); ++i){
            for(int j = coins[i]; j < amount+1; ++j){
                dp[j] = min(dp[j], dp[j-coins[i]] + 1);
            }
        }

        // 返回
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end

// 笔记：其实背包问题还没有理解透彻，尤其是数组初始化部分。

