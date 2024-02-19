/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        if(nums.empty()){
            return nums;
        }

        /*
        // 解法一：暴力检索
        for(int i = 0; i < nums.size(); ++i){
            nums[i]*=nums[i];
        }

        sort(nums.begin(),nums.end());

        return nums;
        */
       
       /*
       // 解法二：双指针法
       vector<int> result(nums.size(), 0);

       int left = 0;
       int right = nums.size()-1;
       int count = 0;
       
       while(left <= right){
           
           if(nums[left]* nums[left] > nums[right] * nums[right]){
               result[nums.size() - ++count]  = nums[left]* nums[left];
               left++;
           }else{
                result[nums.size() - ++count]  = nums[right]* nums[right];
                right--;
           }
       }

       return result;
       */


       // 解法三：标准答案
       vector<int> result(nums.size(), 0);
       int k = nums.size() - 1;

       for(int i = 0, j = nums.size() - 1; i <= j;){
          if(nums[i] * nums[i] > nums[j] * nums[j]){
            result[k] = nums[i] * nums[i];
            i++;
          }else{
            result[k] = nums[j] * nums[j];
            j--;
          }
          k--;
       }

       return result;

    }
};
// @lc code=end


// 笔记
// 1. 可以调用vector内置函数
// 2. 数组原地移除是最不方便的

