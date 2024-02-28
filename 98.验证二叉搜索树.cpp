/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    void traversal(TreeNode* cur, vector<int>& res){
        // 递归出口
        if(cur == nullptr) return;

        traversal(cur->left, res);
        res.push_back(cur->val);
        traversal(cur->right, res);

        return;
    }


    bool isValidBST(TreeNode* root) {
        // 参数检验
        if(root == nullptr){
            return false;
        }

        // 递归：返回数组
        vector<int> res;
        traversal(root, res);

        // 遍历 res
        if(res.size() == 1){
            return true;
        }
        for(int i =0 ; i < res.size()-1; ++i){
            if(res[i] >= res[i+1]){
                return false;
            }
        }

        // 返回
        return true;
    }
};
// @lc code=end

// 笔记：
// 1. 陷阱一：不能单纯比较左小于中，右大于中，就完事了。
// 2. 要利用中序遍历单增特性：递增。只要每一次都记录中间指针的位置，当下一次遍历时也就代表着记录前指针的位置了。

