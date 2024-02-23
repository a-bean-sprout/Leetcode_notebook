/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

#include<string>
#include<stack>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        // 参数检验
        if(s.empty()){
            return s;
        }

        // 遍历元素，更新栈。不同时插入，相同时删除
        stack<char> st;
        for(char si: s){
            if(st.empty() || st.top() != si){
                st.push(si);
            }else{
                st.pop();
            }
        }

        // 栈转化为字符串
        string result;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        // 返回
        reverse (result.begin(), result.end());

        return result;
    }
};
// @lc code=end
// 笔记
// 个人：实质上也是匹配问题，也就是栈的经典应用