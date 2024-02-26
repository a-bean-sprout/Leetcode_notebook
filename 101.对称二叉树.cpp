/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

    bool compare(TreeNode* left, TreeNode*right){
        // 判断是否对称
        if(left == nullptr && right == nullptr) return true;
        else if(left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right != nullptr) return false;
        else if(left->val != right->val) return false;

        return compare(left->left, right->right) && compare(left->right, right->left);
    }


    bool isSymmetric(TreeNode* root) {
        // 参数检查
        if(root == nullptr){
            return true;
        }
        return compare(root->left, root->right);
    }
};
// @lc code=end

// 思路：判断左右子树是否相等呗
// 最适合使用后序遍历，因为需要先判断左右子树是否相等。先左判断，再右判断，中判断条件。

// 也可以使用迭代法，成双成对的压入栈

