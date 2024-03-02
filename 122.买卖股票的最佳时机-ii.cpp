/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        // 参数检验
        if(prices.empty()){
            return 0;
        }
        
        // 计算利润、贪心算法
        int result = 0;
        for(int i = 0; i < prices.size() - 1; ++i){
            if(prices[i+1] - prices[i] > 0){
                result += (prices[i+1] - prices[i]);
            }
        }

        // 返回结果
        return result;
    }
};
// @lc code=end

