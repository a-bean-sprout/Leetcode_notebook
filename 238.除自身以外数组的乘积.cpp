/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return {};
        }

        // 元素的左积
        vector<int> res(nums.size(), 1);
        int left = 1;
        int right = 1;
        for(int i = 0; i < res.size(); ++i){
            res[i] *= left;
            left *= nums[i];

            res[res.size()-1-i] *= right;
            right *= nums[res.size()-1-i];
        }

        // 返回
        return res;
    }
};
// @lc code=end

