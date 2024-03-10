/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1,-1};
        }

        int left = 0;
        int right = nums.size() - 1;

        int result1 = -1;
        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                result1 = mid;
                right = mid - 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        if(result1 == -1){
            return {-1, -1};
        }

        left = 0, right = nums.size() - 1;
        int result2 =  nums.size();
        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] > target){
                result2 = mid;
                right = mid - 1;
            }else if (nums[mid] < target)
            {
                left = mid + 1;
            }else{
                left = mid + 1;
            }
            
        }

        return {result1, result2 -1};
    }
};
// @lc code=end

// 步骤：
// 1. 查找元素的第一个位置
// 2. 查找第一个大于元素的位置
// 3. - 1；

