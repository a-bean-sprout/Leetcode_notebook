/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
#include<vector>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        // 参数检验
        if(a == nullptr || b == nullptr){
            return a == nullptr ? b : a;
        }

        // 合并
        ListNode* fakeNode = new ListNode();

        ListNode* cur = fakeNode;
        ListNode* curA = a;
        ListNode* curB = b;

        while(curA != nullptr && curB != nullptr){

            if(curA->val < curB->val){
                cur->next = curA;
                curA = curA->next;
            }else{
                cur->next = curB;
                curB = curB->next;
            }

            cur = cur->next;
        }

        cur->next = curA == nullptr? curB : curA;

        // 返回
        return fakeNode->next;
    }

    ListNode* merge(vector<ListNode*>& lists, int begin, int end){
        // 递归出口
        if(begin == end){
            return lists[begin];
        }

        int mid = (begin + end) / 2;
        ListNode* left = merge(lists, begin, mid);
        ListNode* right = merge(lists, mid+1, end);

        return mergeTwoLists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }

        return merge(lists,0,lists.size()-1);
    }
};
// @lc code=end

