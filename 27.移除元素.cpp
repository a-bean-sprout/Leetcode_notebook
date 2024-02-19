/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if(nums.empty())
            return 0;

        /*
        // 解法一：暴力求解
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            if(nums[i] == val){
                for(int j = i +1; j < size; ++j){
                    nums[j-1] = nums[j];
                }
                --i;
                --size;
            }
        }

        return size;
        */

       // 双指针解法
       int slowIndex = 0;
       for(int i =0; i < nums.size(); ++i){
            if(nums[i] == val){
                continue;
            }

            nums[slowIndex++] = nums[i];
       }

       return slowIndex;

    }
};
// @lc code=end

// 笔记
// 1. 数组是连续的，移动元素只能覆盖
// 2. 快慢指针法