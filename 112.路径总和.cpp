/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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

    bool traversal(TreeNode* node, int count){
        // 递归出口
        if(node->left == nullptr && node->right == nullptr){
            if(count == node->val){
                return true;
            }else{
                return false;
            }
        }

        // 左右子树，注意回溯
        if(node->left != nullptr){
            if(traversal(node->left, count - node->val)){
                return true;
            }
        }

        if(node->right != nullptr){
            if(traversal(node->right, count - node->val)){
                return true;
            }
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        // 参数检验
        if(root == nullptr){
            return false;
        }

        // 递归
        return traversal(root,targetSum);

        // 返回
    }
};
// @lc code=end

// 并未正确理解递归
// 

