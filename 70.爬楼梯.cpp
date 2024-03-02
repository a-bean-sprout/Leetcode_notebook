/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // 参数检验
        if(n < 3) return n;

        // 动态规划
        // 1. 建立DP数组，确定下标含义
        // 2. 确定递归公式
        // 3. 初始化数组
        // 4. 确定递归方向
        // 5. 递归赋值
        vector<int> res(n+1,0);
        res[1] = 1;
        res[2] = 2;
        for(int i =3; i < res.size(); ++i){
            res[i] = res[i-1] + res[i-2];
        }

        // 返回结果
        return res[n];
    }
};
// @lc code=end

