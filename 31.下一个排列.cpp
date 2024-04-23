/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return;
        }

        // 倒序遍历找分界点
        int index = nums.size() - 2;
        while(index >= 0){
            if(nums[index] < nums[index+1]){
                break;
            }

            index--;
        }

        if(index >= 0){

            int minMoreThanvalue = nums[index+1];
            int minMoreThanIndex = index+1;
            int i = index+1;
            while(i < nums.size()){
                if(nums[i] > nums[index] && minMoreThanvalue >= nums[i] ){  // 这里注意是大于等于
                    minMoreThanvalue = nums[i];
                    minMoreThanIndex = i;
                }
                i++;
            }
            swap(nums[index],nums[minMoreThanIndex]);
        }
        

        int left = index+1;
        int right = nums.size()-1;
        while(left <= right){
            swap(nums[left++], nums[right--]);
        }

        return;

    }
};
// @lc code=end

// 笔记：
// 目的是找到一个序列，大于当前的序列。但是希望变动的幅度尽可能小
// 1. 使左边较小数，与右边较大数交换。得到之后的序列
// 2. 较小数要尽可能靠右，且较大数要尽可能小

