/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        int result = nums[0];
        for(int i = 1; i < dp.size(); ++i){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            result = max(result, dp[i]);
        }

        return result;
    }
};
// @lc code=end

