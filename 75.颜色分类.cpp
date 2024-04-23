/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:

    void sortColors(vector<int>& nums) {
        // 参数检验
        if(nums.empty() || nums.size() == 1){
            return; 
        }
        int left = 0;
        int right = nums.size() - 1;
        int index = 0;
        // 指针法
        while(index <= right){
            if(nums[index] == 0){
                swap(nums[index++], nums[left++]);
            }else if(nums[index] == 2){
                swap(nums[index], nums[right--]);
            }else{
                index++; // 保证[left, index-1] 均为1
            }
        }

        // 返回
    }
};
// @lc code=end

// 这里其实是双指针法的特殊应用
// 任意时刻需要保证：
// [0-left-1] 0
// [left, i-1] 1
// [right, 末尾] 2
 
