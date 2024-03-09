/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void vector_swap(vector<int>& nums, int begin, int end){
        for(int i = begin, j = end; i < j ; i++, j--){
            swap(nums[i], nums[j]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()){
            return;
        }

        k = k % nums.size();

        vector_swap(nums, 0, nums.size()-1);
        vector_swap(nums, 0, k-1);
        vector_swap(nums, k, nums.size()-1);

        return;
    }
};
// @lc code=end

