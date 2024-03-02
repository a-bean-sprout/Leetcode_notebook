/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtraceing(vector<int>& nums, vector<bool>& used){
        // 递归出口
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        // 递归
        for(int i = 0; i < nums.size(); ++i){
            if(used[i] == true){
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;

            backtraceing(nums, used);

            path.pop_back();
            used[i] = false;
        }

        // 返回
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return {};
        }
        
        // used初始化
        // 递归
        vector<bool> used(nums.size(), false);
        backtraceing(nums, used);

        // 结果返回
        return res;
    }
};
// @lc code=end

