/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrace(int startIndex, int sum, int k){
        // 递归结束，处理结果
        if(path.size() == k){
            if(sum == 0){
                res.push_back(path);
            }
            return;
        }

        // 递归
        for(int i = startIndex; i < 9 && 9 - i >= k - path.size(); ++i){
            path.push_back(i+1);
            sum -= (i+1);

            backtrace(i+1,sum,k);

            path.pop_back();
            sum += (i +1);
        }

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        // 参数检查
        if(k > 9 && n > 45){
            return {};
        }

        // 递归
        backtrace(0, n, k);

        // 返回
        return res;
    }
};
// @lc code=end

// 递归出口：有两种，一种是树的那种，不断往下走，通过条件判断。
// 另一种是树这种，提前判断好了。

// 其实求和的剪支，从0开始加比较方便，以便后序剪支。sum > n，剪掉
// 上述代码未给出剪支策略，需要注意

