/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        // 参数检验
        if(prices.empty()){
            return 0;
        }

        vector<vector<int>> dp(2, vector<int>(prices.size(),0));
        
        dp[0][0] = -prices[0]; //持有
        dp[1][0] = 0;  // 不持有

        for(int i = 1; i < prices.size(); ++i){
            dp[0][i] = max(dp[0][i-1], -prices[i]); //持有
            dp[1][i] = max(dp[1][i-1], prices[i] + dp[0][i-1]); //不持有
        }

        return dp.back().back();

    }
};
// @lc code=end

