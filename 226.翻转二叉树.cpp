/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
#include<string>
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
    TreeNode* invertTree(TreeNode* root) {

        // 参数检查
        if(root == nullptr){
            return nullptr;
        }

        // 先序遍历：中左右，入栈顺序为中右左
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();

            swap(cur->left, cur->right);
            
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        

        // 结果返回
        return root;
    }
};
// @lc code=end

// 这个题是遍历二叉树的变形题
// 但注意不能使用中序二叉树，中间节点一旦遍历，左右节点换序了，影响正常遍历。
