/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:

    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()){
            return 0;
        }

        if(nums.back() < target){
            return nums.size();
        }

        int begin = 0;
        int end = nums.size() -1;

        while(begin < end){  // 目标：大于目标值的第一个元素
            int middle = (begin + end) / 2;

            if(nums[middle] < target){
                begin = middle + 1;
            }else if(nums[middle] > target){
                end = middle;
            }else{
                return middle;
            }
        }

        return begin;
    }
};
// @lc code=end

