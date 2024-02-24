/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include<string>
#include<stack>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 参数检验
        if(temperatures.empty()){
            return temperatures;
        }

        // 遍历输入，更新单调栈，如果元素大于栈顶元素，那么弹出。否则，入栈
        stack<int> index_st;
        vector<int> result(temperatures.size(),0);

        for(int i = 0; i < temperatures.size(); ++i){

            if(index_st.empty() || temperatures[i] <= temperatures[index_st.top()]){
                index_st.push(i);
                continue;
            }

            while(!index_st.empty() && temperatures[i] > temperatures[index_st.top()]){
                result[index_st.top()] = i - index_st.top();
                index_st.pop();
            }

            index_st.push(i);
        }

        // 返回结果
        return result;
    }
};
// @lc code=end

// 笔记：
// 该题目是找到某数左侧的第一个大数，使用单调栈来完成

