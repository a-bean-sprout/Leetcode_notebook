/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode* searchBST(TreeNode* root, int val) {

        // 以下为递归法
        // // 递归出口
        // if(root == nullptr || root->val == val){
        //     return root;
        // }

        // // 递归逻辑
        // if(val > root->val){
        //     return searchBST(root->right, val);
        // }else{
        //     return searchBST(root->left, val);
        // }

        // 参数检验
        if(root == nullptr){
            return nullptr;
        }

        // 遍历
        TreeNode* cur = root;
        while(cur){
            if(cur->val == val){
                return cur;
            }else if(cur->val > val){
                cur = cur->left;
            }else{
                cur = cur->right;
            }
        }

        // 返回
        return cur;
    }
};
// @lc code=end

