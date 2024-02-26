/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include<queue>
using namespace std;

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

    // 迭代法:
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     // 参数判断
    //     if(root == nullptr){
    //         return {};
    //     }

    //     queue<TreeNode*> que;
    //     que.push(root);

    //     vector<vector<int>> res;
    //     while(!que.empty()){
    //         int size = que.size();
    //         vector<int> vec;

    //         while(size--){
    //             TreeNode * cur = que.front();
    //             que.pop();

    //             vec.push_back(cur->val);
    //             if(cur->left) que.push(cur->left);
    //             if(cur->right) que.push(cur->right);
    //         }
            
    //         res.push_back(vec);
    //     }

    //     // 返回结果
    //     return res;

    // }

    void order(TreeNode* cur, vector<vector<int>>& res, int depth){
        if(cur == nullptr) return;

        if(res.size() == depth) res.push_back(vector<int>());

        res[depth].push_back(cur->val);
        
        order(cur->left,res,depth+1);
        order(cur->right,res,depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        // 参数判断

        // 根据层数构建数组
        vector<vector<int>> res;
        order(root, res, 0);

        // 返回
        return res;

    }
};
// @lc code=end

// 递归的写法
// 1. 确定递归函数的参数和返回值
// 2. 确定终止条件
// 3. 确定单层的递归逻辑


