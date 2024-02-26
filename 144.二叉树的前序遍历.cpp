/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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

    void traversal(TreeNode* cur, vector<int>& vec){
        if(cur == nullptr){
            return;
        }

        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // 参数检验
        if(root == nullptr){
            return {};
        }

        // 递归
        vector<int> res;
        traversal(root, res);

        // 返回
        return res;
    }
};
// @lc code=end

// 笔记：树的遍历本质是栈，也就是会先入后出。

// 先后序遍历可参考：https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html#%E6%80%9D%E8%B7%AF
// 先序遍历的迭代解法：如何将问题转化为子问题，子问题就是栈顶元素的节点。

// 中序遍历：稍有难度，给定头节点后元素的访问顺序，和中序顺序不一致。中序要从底部开始

// 后序遍历：后序遍历是先序遍历的迭代，中左右 -> 中右左 -> 左右中
