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

        int left = 0;
        int right = nums.size() -1;

        int result = nums.size();
        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                result = mid;
                right = mid - 1;
            }else if (target < nums[mid]){
                result = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }



        return result;
    }
};
// @lc code=end

