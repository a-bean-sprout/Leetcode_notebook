/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        // 递归出口
        if(inorder.empty()){
            return nullptr;
        }

        // 递归：中左后

        // 中：
        // 1.取后序遍历最后一个元素，建立树节点
        int val = postorder[postorder.size()-1];
        TreeNode* node = new TreeNode(val);

        if(postorder.size() == 1){
            return node;
        }

        // 2.切分中序遍历数组
        int val_index;
        for(val_index =0; val_index < inorder.size(); ++val_index){
            if(inorder[val_index] == val){
                break;
            }
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin()+val_index);
        vector<int> rightInorder(inorder.begin() + val_index + 1, inorder.end());

        // 3.切分后序遍历数组
        postorder.pop_back();

        vector<int> leftPostorder(postorder.begin(),postorder.begin() + val_index);
        vector<int> rightPostorder(postorder.begin() + val_index, postorder.end());

        // 左：
        node->left = traversal(leftInorder, leftPostorder);
        node->right = traversal(rightInorder, rightPostorder);

        // 返回
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 参数检验
        if(inorder.empty() || inorder.size() != postorder.size()){
            return nullptr;
        }

        // 递归：建立子树的问题
        return traversal(inorder, postorder);

        // 结果返回
    }
};
// @lc code=end

// TODO vector开辟空间费时费力，可以通过下表索引来简化

