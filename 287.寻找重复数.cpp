/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return -1;
        }

        int left = 1;
        int right = nums.size() - 1;

        while(left < right){  // 找的是一个突变的边界
            int mid = (left + right) / 2;

            int count = 0;
            for(auto& num:nums){
                if(num <= mid){ // 小于等于mid的个数，正常其个数应该=mid。
                    count++;
                }
            }

            if(count > mid){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        
        return left;
    }
};
// @lc code=end


// 这道题其实可以使用二分
// 假设ct[i]表示，数组内小于等于元素i的个数。那么这个数组是单调递增的。
// 因此可以使用二分

