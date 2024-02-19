/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {

        if(head == nullptr)
            return nullptr;
        
        /*
        // 个人解题思路
        // 头节点不能丢，可先处理头部 && 删除链表涉及两个元素，一般删除第二个元素
        while(head != nullptr && head->val == val){
            ListNode* temp = head->next;
            delete head;
            head = temp;
        }

        ListNode* cur = head;
        while(cur != nullptr && cur->next != nullptr ){

            if(cur->next->val == val){
                ListNode* temp = cur->next->next;
                delete cur->next;
                cur->next = temp;
            }else{
                cur = cur->next;
            }
        }

        return head;
        */

       // 虚拟头节点
       ListNode* dummyHead = new ListNode(0, head);

       ListNode* cur = dummyHead;
        while(cur != nullptr && cur->next != nullptr){

            if(cur->next->val == val){
                ListNode* temp = cur->next->next;
                delete cur->next;
                cur->next = temp;
            }else{
                cur = cur->next;
            }
        }

        return dummyHead->next;
    }
};
// @lc code=end

// 笔记：
// 1. 删除链表：涉及两个元素，比如，第一个元素准备重新赋值 cur->next = cur->next->next。第二个元素删除。
// 2. 删除链表：头节点和中间节点的删除逻辑不一样，所以最好设置一个虚头节点
// 3. 变量定义都忘了


