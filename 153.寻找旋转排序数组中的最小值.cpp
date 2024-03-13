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
        int result;
        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] <= nums.back()){ // 右边递增区间
                result = nums[mid];
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }

        return result;
    }
};
// @lc code=end

