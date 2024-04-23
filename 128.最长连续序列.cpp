/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include<vector>
#include<set>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return 0;
        }

        // 存入Set中
        set<int> num_set;
        for(auto& num:nums){
            num_set.insert(num);
        }

        // 枚举Set，如果N-1不在set中，开始统计
        int max_result = 0;
        for(auto num : num_set){
            if(!num_set.count(num-1)){
                
                int result = 0;
                while(num_set.count(num++)){
                    result++;
                }

                max_result = max(max_result, result);
            }
        }

        // 返回
        return max_result;
    }
};
// @lc code=end

