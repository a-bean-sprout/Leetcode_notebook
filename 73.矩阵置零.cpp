/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 参数检验
        if(matrix.empty()){
            return;
        }

        // 第一行 / 第一列 提前判断
        bool row = false, col = false;
        for(int i = 0; i < matrix.size(); ++i){
            if(!matrix[i][0]){
                col = true;
                break;
            }
        }

        for(int j = 0; j < matrix[0].size(); ++j){
            if(!matrix[0][j]){
                row = true;
                break;
            }
        }

        // 遍历矩阵，标记位置
        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size(); ++j){
                if(!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // 置0操作
        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size(); ++j){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
        }

        if(row){
            for(int j = 0; j < matrix[0].size(); ++j){
                matrix[0][j] = 0;
            }
        }

        if(col){
            for(int i = 0; i < matrix.size(); ++i){
                matrix[i][0] = 0;
            }
        }

        return;
    }
};
// @lc code=end

