/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];  // 左界增序
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return {};
        }

        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res = {intervals[0]};
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] <= res.back()[1]){
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }else{
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
// @lc code=end

// 1. 排序：
// 2. 

