/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

    int min_diff = INT_MAX; 
    TreeNode* pre = nullptr;
    void traversal(TreeNode* cur){
        // 递归出口
        if(cur == nullptr) return;

        // 左中右
        traversal(cur->left);

        if(pre != nullptr){
            min_diff = min_diff < cur->val - pre->val ? min_diff: cur->val - pre->val;
        }
        pre = cur;

        traversal(cur->right);

        // 返回
        return; 
    }

    int getMinimumDifference(TreeNode* root) {
        // 参数检验
        if(root == nullptr){
            return -1;
        }

        // 递归遍历
        traversal(root);

        // 返回
        return min_diff;
    }
};
// @lc code=end

