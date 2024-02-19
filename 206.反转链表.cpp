/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* reverse(ListNode* pre, ListNode*cur){
        if(cur == nullptr){
            return pre;
        }

        ListNode* curNext = cur->next;
        cur->next = pre;

        return reverse(cur, curNext);
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }

        /*
        // 双指针法
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while(cur != nullptr){
            ListNode* curNext = cur->next;

            cur->next = pre;
            pre = cur;
            cur = curNext;
        }

        return pre;
        */

       // 递归法
       return reverse(nullptr, head);
    }
};
// @lc code=end

// 笔记
// 1. 反转链表相对简单：双指针法和递归法均可
// 2. TODO：另一种从后往前递归的思路同样有趣

