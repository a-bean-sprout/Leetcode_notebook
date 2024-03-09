/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return 0;
        }

        // 递推
        // 1.构建递推数组，确定下标含义
        // 2.递推公式
        // 3.初始化
        // 4.递推
        vector<int> dp(nums.size(), 1);  // 包含元素i的最长子序列

        int result = 1;
        for(int i = 1; i < dp.size(); ++i){
            for(int j = 0; j < i; ++j){
               if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
               }
            }
            result = max(result, dp[i]);
        }
        // 返回
        return result;
    }
};
// @lc code=end

// 笔记：
// 给你一个整数数组，找到其中最长递增子序列的长度
// 递推公式： dp[i] = max(dp[j] + 1) [j=0~i-1]


// 这个题出错了，没有明确下标含义