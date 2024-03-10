/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 参数检验
        if(matrix.empty()){
            return;
        }
 
        // 上下翻转
        for(int i = 0 , j = matrix.size()-1; i < j; ++i, --j){
            swap(matrix[i], matrix[j]);
        }

        // 对角线反转
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < i; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        return;
    }
};
// @lc code=end

