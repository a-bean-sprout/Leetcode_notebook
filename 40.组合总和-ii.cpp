/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtraceing(vector<int>& candidates, int beginIndex, int sum, int target){
        // 递归出口 + 结果处理
        if(sum == target){
            res.push_back(path);
            return;
        }

        // 递归逻辑：遍历子树
        for(int i = beginIndex; i < candidates.size() && sum + candidates[i] <= target; ++i){
            // 层去重
            if(i > beginIndex && candidates[i-1] == candidates[i]){
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];

            backtraceing(candidates, i+1, sum, target);

            path.pop_back();
            sum -= candidates[i];
        }

        // 返回
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 参数检验
        if(candidates.empty()){
            return {};
        }

        // 排序
        sort(candidates.begin(), candidates.end());

        // 递归
        backtraceing(candidates, 0, 0, target); 

        // 返回
        return res;
    }
};
// @lc code=end

// 笔记：
// 注意题目：一般都会要求不能包含重复元素，也就是需要往后取，也就是在cur = i的时候，往 i之后取下一个元素。
// 但不能包含重复元素可以有两种解决：一种是上面这种，另一种是要看看是否集合里的元素重复了

