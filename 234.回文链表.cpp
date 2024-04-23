/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 参数检验

        // 快慢指针
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast->next != nullptr){
            slow = slow->next;
        }

        // 翻转链表
        ListNode* pre = nullptr;
        ListNode* cur = slow;
        while(cur != nullptr){
            ListNode* curNext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = curNext;
        }

        cur = head;
        while(pre != nullptr & cur != nullptr){
            if(pre->val != cur->val){
                return false;
            }
            pre = pre->next;
            cur = cur->next;
        }

        return true;
    }
};
// @lc code=end

