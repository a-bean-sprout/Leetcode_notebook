/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    const string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> res;
    string path;

    void backtraceing(int beginIndex, string digits){
        // 递归出口，结果处理
        if(beginIndex == digits.size()){
            res.push_back(path);
            return;
        }

        // 递归回溯
        string letter =letterMap[digits[beginIndex] - '0'];
        for(int i = 0; i < letter.size(); ++i){
            path.push_back(letter[i]);
            backtraceing(beginIndex + 1, digits);
            path.pop_back();
        }

        // 返回
        return;
    }

    vector<string> letterCombinations(string digits) {
        // 参数检查
        if(digits.empty()){
            return {};
        }

        // 递归
        backtraceing(0, digits);

        // 结果返回
        return res;
    }
};
// @lc code=end

