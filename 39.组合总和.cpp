/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res_vec;
    vector<int> res;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
        // step1:递归出口,收集结果
        if(sum > target){
            return;
        }

        if(sum == target){
            res_vec.push_back(res);
            return;
        }

        // step2: 递推回溯
        for(int i = startIndex ; i < candidates.size() && sum + candidates[i] <= target; ++i){
            res.push_back(candidates[i]);
            backtracking(candidates, target, sum + candidates[i], i);
            res.pop_back();
        }

        return;
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 参数检验
        if(candidates.empty()){
            return {};
        }

        // 递归
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0 , 0);

        // 返回
        return res_vec;
    }

    // 求和问题
};
// @lc code=end

