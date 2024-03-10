/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 参数检验
        if(matrix.empty()){
            return false;
        }

        // 类似二分消边迭代
        int i = matrix.size()-1, j = 0;
        while(i >=0 && j < matrix[0].size()){
            if(matrix[i][j] < target ){
                j++;
            }else if (matrix[i][j] > target){
                i--;
            }else{
                return true;
            }
        }

        // 返回
        return false;
    }
};
// @lc code=end

// 每行元素从左到右升序排列
// 每列元素从上到下升序排列

// 解法：以右下角为标志

