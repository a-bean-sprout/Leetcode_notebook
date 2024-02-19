/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // 解法一：暴力遍历

        // 解法二：滑动窗口
        if(nums.empty()){
            return 0;
        }
        
        int total = 0;
        int min_len = INT32_MAX;
        for(int left=0, right=0; right < nums.size(); ++right){

            total += nums[right];

           while(total >= target){
             int len = right - left + 1;
             min_len = min_len > len ? len: min_len;
             total -= nums[left];
             left++;
           }

        }

        return min_len == INT32_MAX ? 0 : min_len;


    }
};
// @lc code=end

// 笔记
// 1. 滑动窗口：利用中间结果完成运算

