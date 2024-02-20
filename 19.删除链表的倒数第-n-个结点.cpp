/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // 删除链表的倒数第n个节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == nullptr){
            return head;
        }

        ListNode* dummyNode = new ListNode(0, head);

        ListNode* fast = dummyNode;
        ListNode* slow = dummyNode;

        while(n-- && fast->next != nullptr){
            fast = fast->next;
        }

        // if(n > 0){
        //     return dummyNode->next;
        // }

        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        // 删除伪节点略
        return dummyNode->next;
    }
};
// @lc code=end

// 笔记：
// 1. 伪头节点：简化运算
// 2. 删除链表：指向前一个节点 
// 3. 提示：双指针的经典题.
// 4. 在自己的逻辑中，尾节点定义为最后一个元素，所以判断条件为fast->next!=null。而官方给出的尾节点为null

