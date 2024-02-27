/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

    int getDepth(TreeNode* node){
        if(node == nullptr) return 0;

        int leftMinDepth = getDepth(node->left);
        int rightMinDepth = getDepth(node->right);

        if(leftMinDepth ==0 && rightMinDepth !=0){
            return rightMinDepth + 1;
        }else if(leftMinDepth !=0 && rightMinDepth==0){
            return leftMinDepth + 1;
        }else {
            return 1 + min(leftMinDepth, rightMinDepth);
        }
    }

    int minDepth(TreeNode* root) {
       // 参数检验
        if(root == nullptr) return 0;
       // 递归:返回最小深度
       int result = getDepth(root);

       // 返回结果
       return result; 
    }
};
// @lc code=end

