/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtraceing(vector<int>& nums, int beginIndex){
        // 递归出口、结果处理
        res.push_back(path);

        if(beginIndex >= nums.size()){
            return;
        }

        // 递归回溯
        for(int i = beginIndex; i< nums.size(); ++i){
            path.push_back(nums[i]);
            backtraceing(nums, i+1);
            path.pop_back();
        }

        // 返回
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return {};
        }

        // 递归
        backtraceing(nums, 0);

        // 结果返回
        return res;
    }
};
// @lc code=end

