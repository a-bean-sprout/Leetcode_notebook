/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:

    int uniquePaths(int m, int n) {
        // 参数检验

        // 动态规划
        vector<vector<int>> res(m, vector<int>(n, 1));

        // 递推公式：res[i][j] = res[i-1][j] + res[i][j-1]
        // 初始化赋值：第一行，第一列为 1

        for(int i = 1; i < res.size(); ++i){
            for(int j = 1;j < res[0].size(); ++j){
                res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }

        // 返回
        return res[m-1][n-1];
    }
};
// @lc code=end

