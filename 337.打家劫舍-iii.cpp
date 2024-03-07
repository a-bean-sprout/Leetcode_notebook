/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> robTree(TreeNode* cur){
        // 递归出口
        if(cur == nullptr){
            return {0, 0}; // 不偷，偷
        }

        // 左
        vector<int> left_res = robTree(cur->left);
        // 右
        vector<int> right_res = robTree(cur->right);

        // 中
        // 如果偷
        int rob = cur->val + left_res[0] + right_res[0];

        // 如果不偷
        int unrob = max(left_res[0], left_res[1]) + max(right_res[0], right_res[1]);

        // 返回
        return {unrob, rob};
    }

    int rob(TreeNode* root) {
        // 参数检验

        // 递归

        // 返回
    }
};
// @lc code=end

