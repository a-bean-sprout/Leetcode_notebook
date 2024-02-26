/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {

        // 参数检验
        if(root == nullptr){
            return {};
        }

        // 个人想法
        // 1. 从当前节点开始，一直往左直到无左节点
        // 2. 将该节点输出，判断其是否有右节点，有则加入。无则返回上一层。
        // 这个思路的问题：无法判断当前节点的左节点是否处理过，就会产生问题
        // 错误点在于：取了当前栈元素，一直往左走了。无法判断是否走过了
        // 所以当取了栈元素，就应该处理，而不能往左走了
        // 错误点在于：取栈元素的功能混淆了，将往左走和处理和二为一了
        // vector<int> res;
        // while(!st.empty()){
        //     TreeNode* cur = st.top();
            
        //     if(cur->left){
        //         st.push(cur->left);
        //     }else{
        //         res.push_back(cur->val);
        //         st.pop();

        //         if(cur->right) st.push(cur->right);
        //     }
        // }

        // 循环
        vector<int> res;
        stack<TreeNode*> st;

        TreeNode* cur = root;
        while(cur != nullptr || !st.empty()){
                if(cur != nullptr){
                    st.push(cur);
                    cur = cur->left;
                }else{
                    cur = st.top();
                    st.pop();

                    res.push_back(cur->val);
                    cur = cur->right;
                }
        }
        


        // 结果返回
        return res;
    }
};
// @lc code=end

