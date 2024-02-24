/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include<string>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        // 参数判断
        if(tokens.empty())
            return 0;
        
        // 遍历输入，增删栈
        stack<long long> st;
        for(int i = 0; i < tokens.size(); ++i){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(stoll(tokens[i]));
            }else{
                // 取两元素
                long long num2 =st.top();
                st.pop();

                long long num1 = st.top();
                st.pop();

                // 执行运算
                if(tokens[i] == "+") st.push(num1+num2);
                else if(tokens[i] == "-") st.push(num1-num2);
                else if(tokens[i] == "*") st.push(num1*num2);
                else if(tokens[i] == "/") st.push(num1/num2);  // 注意：这里特别容易错
            }

            cout << st.top();
        }
        // 返回结果
        return st.top();
    }
};
// @lc code=end


int main(){
    Solution x = Solution();
    vector<string> ilist = {"4","13","5","/","+"};
    cout << x.evalRPN(ilist) << endl;
    return 0;
}
// 笔记：使用栈来完成
// long long 数据结构
// 字符串 到 ll 的转换

