/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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

    vector<string> res_string_vec;

    void traversal(TreeNode* node, vector<int>& res){
        res.push_back(node->val);

        // 递归截止
        if(node->left == nullptr && node->right == nullptr){
            // 处理 res , 拼接为字符串
        }

        if(node->left != nullptr) {
            traversal(node->left, res);
            res.pop_back();
        }

        if(node->right != nullptr){
            traversal(node->right, res);
            res.pop_back();
        }
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        // 参数检查

        // 递归：子问题，返回节点

        // 返回结果
    }
};
// @lc code=end

