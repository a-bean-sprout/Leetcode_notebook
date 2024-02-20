/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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

#include <valarray>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // 参数检查
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        // 计算链表长度
        ListNode* curA = headA;
        ListNode* curB = headB;

        int lenA = 0,lenB = 0;
        while(curA->next != nullptr){
            curA = curA->next;
            ++lenA;
        }

        while(curB->next != nullptr){
            curB = curB->next;
            ++lenB;
        }
        
        // 这里很漂亮，让A变成长链表
        curA = headA;
        curB = headB;

        if(lenB > lenA){
            swap(lenB,lenA);
            swap(curB,curA);
        }

        // 差值移动
        int diff = lenA - lenB;
        while(diff--){
            curA = curA->next;
        }

        while(curA != curB && curA != nullptr){
            curA = curA->next;
            curB = curB->next;
        }

        return curA;
    }
};
// @lc code=end

// 笔记
// 1. 思路：最笨的方法是暴力双循环，一般可用双指针来改进。
// 2. 但这题思路为找规律：链表一旦相交，就不会分开。所以可判断倒数第几个元素开始不同，来得到相交元素。
// 3. 但是链表不具备倒数的属性，所以要正向数。
// 4. 思路有了要先写注释，分块。

