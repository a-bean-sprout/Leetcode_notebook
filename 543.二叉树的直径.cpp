/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
#include <vector>
#include <iostream>
using namespace std;

// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int max_result = INT_MIN;
    int TreeDepth(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        int left_depth = TreeDepth(node->left);
        int right_depth = TreeDepth(node->right);

        max_result = max(max_result, left_depth + right_depth);

        return max(left_depth, right_depth) + 1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        // 参数检验
        if(root == nullptr){
            return 0;
        }

        TreeDepth(root);

        return max_result;
    }
};
// @lc code=end

