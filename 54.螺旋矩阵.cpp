/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 参数检验
        if(matrix.empty()){
            return {};
        }

        // 遍历
        int row_begin = 0, col_begin = 0;
        int row_end = matrix.size()-1, col_end = matrix[0].size()-1;

        vector<int> res;
        while(true){
            for(int i = col_begin; i <= col_end; ++i){
                res.push_back(matrix[row_begin][i]);
            }
            if(++row_begin > row_end) break;

            for(int i = row_begin; i <= row_end; ++i){
                res.push_back(matrix[i][col_end]);
            }
            if(--col_end < col_begin) break;

            for(int i = col_end; i >= col_begin; --i){
                res.push_back(matrix[row_end][i]);
            }
            if(--row_end < row_begin) break;

            for(int i = row_end; i >= row_begin; --i){
                res.push_back(matrix[i][col_begin]);
            }
            if(++col_begin > col_end) break;
        }

        return res;
    }
};
// @lc code=end

