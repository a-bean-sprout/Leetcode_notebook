/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        // 参数检验
        if(n <=0){
            return 0;
        }

        // 完全背包问题
        // 1. 初始化数组，明确下标含义
        vector<int> dp(n+1, n+1);

        // 2. 确定递推公式
        // dp[j] = min(dp[j], dp[j-i*i] + 1)

        // 3. 初始化
        dp[0] = 0;

        // 4. 递推
        for(int i = 1 ; i <= sqrt(n) ; ++i){
            for(int j = i*i; j < n+1 ; ++j){
                dp[j] = min(dp[j], dp[j - i*i] + 1);
            }
        }

        // 返回
        return dp[n] > n ? -1 : dp[n];
    }
};
// @lc code=end

// 笔记：
// 其实也是背包问题： dp[i][j] = min(dp[i-1][j], dp[i][j-w[i]]+1)

