/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder, int preorderBegin, int preorderEnd, int inorderBegin, int inorderEnd){
        // 递归出口
        if(preorderBegin > preorderEnd || inorderBegin > inorderEnd){
            return nullptr;
        }

        // 直接返回
        TreeNode* cur = new TreeNode(preorder[preorderBegin]);

        if(preorderBegin == preorderEnd){
            return cur;
        }

        // 1
        int splitVal = preorder[preorderBegin];

        int index = inorderBegin;
        for(; index <= inorderEnd; ++index){
            if(inorder[index] == splitVal){
                break;
            }
        }

        int preorderIndex = (index - inorderBegin) + preorderBegin;

        cur->left = traversal(preorder, inorder, preorderBegin+1, preorderIndex, inorderBegin,index-1);
        cur->right = traversal(preorder, inorder, preorderIndex+1, preorderEnd, index+1,inorderEnd);

        // 返回
        return cur;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return nullptr;
        }

        return traversal(preorder, inorder, 0, preorder.size()-1, 0 , inorder.size()-1);
    }
};
// @lc code=end

// 递归法：
// 1. 先序遍历找中间节点
// 2. 根据中间节点将中序遍历二分，得其左右
// 3. 根据左右长度切分先序遍历
// 4. 递归处理

// trick: 使用数组索引值更方便

