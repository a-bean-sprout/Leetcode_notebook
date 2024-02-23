/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include<string>
#include<stack>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        
        // 参数判断
        if(s.empty() && s.size()%2 == 1){
            return false;
        }

        // 遍历 S，更新栈，左则增，右则剪
        stack<char> s_stack;
        for(int i = 0; i< s.size(); ++i){
            if(s[i] == '(') s_stack.push(')');
            else if(s[i] == '{') s_stack.push('}');
            else if(s[i] == '[') s_stack.push(']');
            else{
                if(s_stack.empty()){
                    return false;
                }

                char s_top = s_stack.top();
                if(s_top != s[i]){
                    return false;
                }

                s_stack.pop();
            }
        }

        if(s_stack.empty()){
            return true;
        }

        return false;

        // return
    }
};
// @lc code=end

// 笔记：由于栈结构的特殊性，非常适合做对称类题目

// 1. char 和 string 的区别要注意
// 2. 原文的代码写的更简练一点，在复习时可以参考

