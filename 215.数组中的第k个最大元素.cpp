/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int quickSelect(vector<int>& nums, int k){

        int value = nums[rand() %  nums.size()];

        vector<int> big,small,equal;
        for(auto& x:nums){
            if(x == value){
                equal.push_back(x);
            }else if( x > value){
                big.push_back(x);
            }else{
                small.push_back(x);
            }
        }

        if( k <= big.size()){
            return quickSelect(big, k);
        }else if( nums.size() - small.size() < k){
            return quickSelect(small, k - (nums.size() - small.size()));
        }

        return value;

    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
};
// @lc code=end

