/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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

    void Traversal(TreeNode* node, vector<int>& res){
        if(node == nullptr) return;

        Traversal(node->left, res);
        Traversal(node->right, res);
        res.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        // 参数检验
        if(root == nullptr){
            return {};
        }

        // 递归：左右中
        vector<int> res;
        Traversal(root,res);

        // 结果返回
        return res;
    }
};
// @lc code=end

