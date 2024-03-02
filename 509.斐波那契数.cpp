/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int fib(int n) {
        // 参数检查
        if( n < 2 ){
            return n;
        }

        // 确定DP数组及下标的含义
        vector<int> dp(n+1, 0);

        // 确定递推公式

        // DP数组初始化
        dp[0] = 0;
        dp[1] = 1;

        // 确定遍历顺序

        // 数组赋值
        for(int n = 2; n < dp.size(); n++){
            dp[n] = dp[n-1] + dp[n-2];
        }

        // 返回
        return dp[n];
    }
};
// @lc code=end

