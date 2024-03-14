/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
// };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 参数检验
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        // 归并排序
        ListNode* slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){  // fast在倒一或倒二处停止
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* left = head;
        ListNode* right = slow->next;

        slow->next = nullptr;

        ListNode* left_result = sortList(left);
        ListNode* right_result = sortList(right);

        ListNode* headFake = new ListNode();
        ListNode* cur = headFake;
        while(left_result != nullptr && right_result != nullptr){
            if(left_result->val < right_result->val){
                cur->next = left_result;
                left_result = left_result->next;
            }else{
                cur->next = right_result;
                right_result = right_result->next;
            }
            cur = cur->next;
        }

        if(left_result){
            cur->next = left_result;
        }

        if(right_result){
            cur->next = right_result;
        }

        return headFake->next;
    }
};
// @lc code=end

