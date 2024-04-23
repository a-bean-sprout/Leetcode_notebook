/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
#include<unordered_map>
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
    unordered_map<long long, int> prefix_map;

    int traversal(TreeNode* cur, long long curSum, int targetSum){
        if(cur == nullptr){
            return 0;
        }

        curSum += cur->val;
        int ret = 0;
        if(prefix_map.count(curSum - targetSum)){
            ret += prefix_map[curSum - targetSum];  // 以当前节点为终点的结果数量
        }

        prefix_map[curSum]++;
        ret += traversal(cur->left, curSum, targetSum);
        ret += traversal(cur->right, curSum, targetSum);
        prefix_map[curSum]--;

        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        // 参数检验
        if(root == nullptr){
            return 0;
        }
        
        prefix_map[0] = 1;

        return traversal(root, 0, targetSum);
        // 递归

        // 返回结构
    }
};
// @lc code=end

// 明确思路：前缀和
// 前缀和Map，存储了从头节点到目标节点，所有路径的前缀map

// 这个题的思路相当巧妙

