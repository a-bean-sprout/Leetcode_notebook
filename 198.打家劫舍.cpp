/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:

    int rob(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return 0;
        }

        // 动态规划
        // 1. 初始化数组，明确下标含义
        // 2. 确定递推公式：dp[i] = max(dp[i-2]+nums[i], dp[i-1])
        // 3. 初始化数组
        // 4. 遍历
        vector<int> dp(nums.size()+1, 0); //下标含义表示包含第i个房间在内的最大价值
        dp[0] = 0;
        dp[1] = nums[0];
        
        for(int i = 2 ; i < dp.size(); ++i){
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }

        // 返回
        return dp.back();
    }
};
// @lc code=end

// 这个题其实相对简单
// dp[i] = max(dp[i-2]+nums[i], dp[i-1])

