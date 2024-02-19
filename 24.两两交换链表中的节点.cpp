/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* dummyNode = new ListNode(0, head);

        ListNode* cur = dummyNode;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode* temp1 = cur->next->next->next;
            ListNode* temp2 = cur->next->next;
            cur->next->next->next = cur->next;
            cur->next->next = temp1;
            cur->next = temp2;

            cur = cur->next->next;
        }
    
        head = dummyNode->next;
        delete dummyNode;   
        return head;

    }
};
// @lc code=end

// 

