/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:

    int change(int amount, vector<int>& coins) {
        // 参数检验

        // 构建DP数组，以及下标含义
        vector<int> dp(amount+1, 0);

        // 确定递推公式
        // dp[i][j] = dp[i-1][j] + dp[i][j-weight]
        // dp[j] += dp[[j-weight]

        // 初始化
        dp[0] = 1;

        // 确定遍历顺序
        for(int i = 0; i < coins.size(); ++i){
            for(int j = coins[i]; j < amount+1; ++j){
                dp[j] += dp[j - coins[i]];
            }
        }

        // 返回
        return dp[amount];
    }
};
// @lc code=end

