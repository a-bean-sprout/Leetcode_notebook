/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* traversal(vector<int>& nums, int left, int right){  // 区间：[left, right)
        // 递归出口
        if(left == right){
            return nullptr;
        }

        // 遍历：中左右
        int middle = (left + right - 1) / 2;
        TreeNode* cur = new TreeNode(nums[middle]);

        cur->left = traversal(nums, left, middle);
        cur->right = traversal(nums, middle + 1, right);
        
        // 返回
        return cur;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return nullptr;
        }

        // 递归
        return traversal(nums, 0, nums.size());

        // 返回
    }
};
// @lc code=end

