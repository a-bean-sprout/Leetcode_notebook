/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()){
            return -1;
        }

        int left = 0, right = nums.size() -1;
        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[0] <= nums[mid]){ // 左边升序

            }
        }
    }
};
// @lc code=end

