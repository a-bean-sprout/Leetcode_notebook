/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        // 参数检查
        if(root == nullptr){
            return {};
        }

        // 层序遍历
        vector<int> res;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();

            while(size--){
                TreeNode* cur = que.front();
                que.pop();

                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);

                if(size == 0){
                    res.push_back(cur->val);
                }
            }
        }

        // 返回
        return res;
    }
};
// @lc code=end

// 再写一遍层序遍历吧，加油小原。
// 

