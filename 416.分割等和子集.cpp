/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return false;
        }

        // 计算背包容量 sum/2
        int sum = 0;
        for(const auto& num:nums){
            sum += num;
        }

        if(sum % 2 == 1){
            return false;
        }

        int cap = sum / 2;

        // 构建dp数组
        vector<int> dp(cap+1, 0);

        // 递推公式
        // dp[i][j] = max(dp[i-1][j], dp[i-1][j-wi] + vi)
        // dp[j] = max(dp[j], dp[j-wi] + vi)
        for(int i = 0; i < nums.size(); ++i){
            for(int j = cap ; j >= nums[i] ; --j ){
                dp[j] = max(dp[j], dp[j -nums[i]] + nums[i]);
            }
        }


        // 返回结果
        return dp.back() == cap;
    }
};
// @lc code=end


// 思路
// 这个题的核心是将问题转化为01背包问题
// 1. 将sum/2容量大小的背包，尽可能的装满。
