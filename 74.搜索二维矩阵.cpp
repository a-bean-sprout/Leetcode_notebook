/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()){
            return false;
        }

        // 拼接为一个单个序列
        int left = 0, right = matrix.size() * matrix[0].size() - 1;

        while(left <= right){
            int middle = (left + right) / 2;

            int value = matrix[middle/matrix[0].size()][middle%matrix[0].size()];

            if(value < target) left = middle + 1;
            else if (value > target) right = middle -1;
            else return true;
        }

        return false;

    }
};
// @lc code=end

