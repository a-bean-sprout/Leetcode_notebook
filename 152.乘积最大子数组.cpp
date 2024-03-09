/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return 0;
        }

        vector<int> dp_max(nums.size(), nums[0]);
        vector<int> dp_min(dp_max);

        int result = nums[0];
        for(int i = 1; i < dp_max.size(); ++i){
            dp_max[i] = max(dp_max[i-1]*nums[i], max(dp_min[i-1]*nums[i], nums[i]));
            dp_min[i] = min(dp_min[i-1]*nums[i], min(dp_max[i-1]*nums[i], nums[i]));

            result = max(result, dp_max[i]);
        }

        return result;
    }
};
// @lc code=end

// dp[i] = max/min(dp[i-1]* nums[i], nums[i]);
