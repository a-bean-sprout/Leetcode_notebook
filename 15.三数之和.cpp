/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 题目：是否存在三元素之和为0。统计后返回，返回的三元组不能重复

        // 参数检验
        vector<vector<int>> result;
        if(nums.size() < 3){
            return result;
        }

        // 将数据排序，构建三个指针，找到就加入结果集
        sort(nums.begin(),nums.end());

        int left, right;
        for(int i = 0; i < nums.size(); ++i){

            if(nums[i] > 0){ // 这个要注意写
                continue;
            }

            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            left = i + 1;
            right = nums.size() - 1;

            while(left < right){  // 注意：left != right 可能会越界，因为i+1是个危险分子
                if((nums[i] + nums[left] + nums[right]) < 0){
                    left++;
                }else if((nums[i] + nums[left] + nums[right]) > 0){
                    right--;
                }else{
                    result.push_back({nums[i], nums[left], nums[right]});

                    while(left < right && nums[left] == nums[left+1]){
                        left++;
                    }

                    while(left < right && nums[right] == nums[right-1]){
                        right--;
                    }
                    
                    left++;
                    right--;
                }
            }
        }
        return result;

    }
};
// @lc code=end

// 笔记
// 个人思路：三重循环 = 两重循环 + hash_set
// 双指针法

