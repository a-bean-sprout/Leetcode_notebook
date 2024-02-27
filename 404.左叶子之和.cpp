/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
#include<queue>
#include<stack>
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

    int traversal(TreeNode* node){
        // 递归出口：叶子节点 + 左节点。 node.left.left && node.left.right
        if(node == nullptr) return 0;
        
        // 遍历顺序：前后中
        int left_count = traversal(node->left);
        if(node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr){
            left_count = node->left->val;
        }
        
        int right_count = traversal(node->right);
        
        // 返回
        return left_count + right_count;
    }


    int sumOfLeftLeaves(TreeNode* root) {
        // 参数检验

        // 递归：子树的左叶子节点之和

        // 结果返回
    }
};
// @lc code=end

// 1. 递归出口的理解

