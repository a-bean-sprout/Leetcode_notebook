/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }

        TreeNode* cur = root;
        while(cur != nullptr){
            if(cur->left != nullptr){  // 直接修改树结构：将左孩子放在右边，右孩子接再左孩子的最右边
                TreeNode* next = cur->left;

                TreeNode* concat = next;
                while(concat->right != nullptr){
                    concat = concat ->right;
                }

                concat->right = cur->right;

                cur->right = cur->left;
                cur->left = nullptr;
            }

            cur = cur ->right;
        }

        return;
    }
};
// @lc code=end

// 思路：
// 这道题可以理解为先序遍历的变形题
// 但是需要修改树结构，所以递归法可能会难想。其实能做，不深究了
// 可以借助栈使用迭代法
// 另一种思路的话，就是修改树的结构