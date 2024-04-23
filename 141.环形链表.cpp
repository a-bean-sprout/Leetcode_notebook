/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 参数检验
        if(head == nullptr){
            return false;
        }

        // 快慢指针
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast){
                return true;
            }
        }

        //返回
        return false;
    }
};
// @lc code=end

