/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> res_vec;
    string res;
    void backtracking(int left, int right, int n){
        // 递归出口
        if(left > n || left < right){ 
            return;
        }

        if(res.size() == 2 * n){
            res_vec.push_back(res);
        }

        for(int i = 0; i < 2; ++i){
            if( i == 0){
                res.push_back('(');
                backtracking(left+1, right, n);
            }else{
                res.push_back(')');
                backtracking(left, right+1, n);
            }
            
            res.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        // 参数检验
        if(n <= 0){
            return {};
        }

        // 递归
        backtracking(0,0,n);

        // 返回
        return res_vec;
    }
};
// @lc code=end

