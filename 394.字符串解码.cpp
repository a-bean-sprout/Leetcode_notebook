/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include<string>
#include<stack>
using namespace std;

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        // 参数检验

        // 遍历，栈存储
        stack<string> strs;
        stack<int> multis;

        int multi = 0;
        string str = "";
        for(auto& x : s){

            if('0' <= x && x <= '9'){
                multi = multi * 10 + (x - '0');
            }else if (x == '['){   // 入栈
                strs.push(str);
                multis.push(multi); 

                multi = 0;
                str = "";
            }else if (x == ']'){
                string preStr = "";
                if(!strs.empty()){
                    preStr = strs.top();
                    strs.pop();
                }
                
                int nums = multis.top();
                multis.pop();

                while(nums--){
                    preStr += str;
                }
                str = preStr;
                
            }else{
                str += x;
            }
            
        }

        return str;
    }
};
// @lc code=end

