/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;

    bool isVaild(int row, int col, int n, vector<string>& chessBoard){

        // 判断列是否
        for(int i = 0; i < row; ++i){
            if(chessBoard[i][col] == 'Q'){
                return false;
            }
        }

        // 判断左对角
        for(int i = row -1, j =col -1; i >=0 && j>=0; --i,--j){
            if(chessBoard[i][j] == 'Q'){
                return false;
            }
        }

        // 判断右对角
        for(int i = row -1, j = col +1; i >=0 && j < n; --i,++j){
            if(chessBoard[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    void backtrace(int row, int n, vector<string>& chessBoard){
        // 递归出口
        if(row == n){
            res.push_back(chessBoard);
            return;
        }

        // 递归回溯
        for(int col = 0; col < n; ++col){
            // 判断是否
            if(!isVaild(row, col, n ,chessBoard)){
                continue;
            }

            chessBoard[row][col] = 'Q';
            backtrace(row+1, n, chessBoard);
            chessBoard[row][col] = '.';
        }

        // 返回
        return;
    }


    vector<vector<string>> solveNQueens(int n) {
        // 参数检查
        if(n <= 0){
            return {};
        }

        // 递归
        vector<string> chessBoard(n, string(n, '.'));
        backtrace(0, n, chessBoard);

        // 返回
        return res;
    }
};
// @lc code=end

// 笔记：string的初始化方法

