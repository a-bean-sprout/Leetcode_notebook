/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include<vector>
#include<unordered_map>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // 参数检验
        if(nums.empty()){
            return nums;
        }

        // 遍历nums，查找元素
        unordered_map<int,int> num_index_map;
        for(int i = 0 ; i < nums.size(); ++i){
            int search_num = target  - nums[i];

            if(num_index_map.find(search_num) != num_index_map.end()){
                return {i ,num_index_map[search_num]};
            }

            num_index_map[nums[i]] = i;
        }

        return {};
        
    }
};
// @lc code=end

// 笔记
// 如果不引入任何数据结构，可以排序后转化为二分查找问题。复杂度（n+2nlogn）
// 注意：查找问题最方便的做法是Hash
// 题解思路中并没有直接全部将元素放入map中：如果在过去不能配对成功，那就等待未来的配对。但其实全插进人也行，找到未来的配对元素。
// vector的返回方法，需注意。{a，b}

