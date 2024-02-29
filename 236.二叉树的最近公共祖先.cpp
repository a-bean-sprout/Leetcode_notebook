/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

    TreeNode* traversal(TreeNode* cur, TreeNode*p, TreeNode*q) {
        // 递归出口
        if(cur == nullptr || cur == p || cur == q){
            return cur;
        }

        // 遍历：左右中
        TreeNode* left = traversal(cur->left, p, q);
        TreeNode* right = traversal(cur->right, p, q);

        // 中：判断
        if(left != nullptr && right != nullptr){
            return cur;
        }else if(left != nullptr && right == nullptr){
            return left;
        }else if (left == nullptr && right != nullptr){
            return right;
        }

        // 返回
        return nullptr;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 参数检验
        if(root == nullptr || p == nullptr || q == nullptr){
            return nullptr;
        }

        // 递归
        TreeNode* res = traversal(root,p,q);

        // 返回
        return res;
    }
};
// @lc code=end

// 笔记：
// 求先祖：pq存在于左或右节点
// 

