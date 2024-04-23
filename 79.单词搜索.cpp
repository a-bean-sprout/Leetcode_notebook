/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool backtracking(vector<vector<char>>& board, string word, int row, int col, int beginIndex){
        // 递归出口
        if(beginIndex == word.size()){
            return true;
        }

        if(row >= board.size() || col >= board[0].size() || row < 0 || col < 0){
            return false;
        }

        if(board[row][col] != word[beginIndex]){
            return false;
        }

        board[row][col] = '\0';

        bool result =  backtracking(board, word, row+1,col,beginIndex+1) || backtracking(board, word, row-1,col,beginIndex+1) || backtracking(board, word, row,col-1,beginIndex+1) || backtracking(board, word, row,col+1,beginIndex+1);
        // 回溯
        board[row][col] = word[beginIndex];

        return result;
    }


    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size() ; ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(backtracking(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};
// @lc code=end

