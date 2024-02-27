/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
        if(node == nullptr) return 0;

        int left_hight = traversal(node->left);

        int right_hight = traversal(node->right);

        if(left_hight == -1 || right_hight == -1){
            return -1;
        }else{
            if(abs(left_hight - right_hight) > 1) return -1;
            else{
                return max(left_hight,right_hight) +1;
            }
        }
    }

    bool isBalanced(TreeNode* root) {

        // 参数检查

        // 递归：子树的高度

        // 返回结果
    }
};
// @lc code=end

