/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
 
class Solution {
public:
    int result = -1;
    void traversal(TreeNode* cur, int& k) {
        if(cur == nullptr){
            return;
        }

        traversal(cur->left, k);
        k--;
        if(k == 0){
            result = cur->val;
            return;
        }

        traversal(cur->right, k);

        return;
    }


    int kthSmallest(TreeNode* root, int k) {
        // 参数检验
        if(root == nullptr || k == 0){
            return -1;
        }

        // 递归
        traversal(root , k);

        // 返回
        return result;
        
    }
};
// @lc code=end

