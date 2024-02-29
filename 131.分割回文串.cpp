/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isCondition(const string& s){
        for(int i = 0, j = s.size()-1; i < j; i++,j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    vector<string> path;
    vector<vector<string>> res;

    void backtraceing(string s, int beginIndex){
        // 递归出口，结果处理
        if(beginIndex >= s.size()){
            res.push_back(path);
            return;
        }

        // 递归、回溯
        for(int i = 1; i <= s.size() - beginIndex; ++i){
            string str = s.substr(beginIndex, i);
            if(!isCondition(str)){
                continue;
            }

            path.push_back(str);
            backtraceing(s, beginIndex + i);
            path.pop_back();
        }

        // 返回
        return;
    }

    vector<vector<string>> partition(string s) {
        // 参数检验
        if(s.empty()){
            return {};
        }

        // 递归
        backtraceing(s, 0);

        // 返回结果
        return res;
    }
};
// @lc code=end

