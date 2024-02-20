/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // 参数检查
        if (head == nullptr){
            return head;
        }

        // 快慢指针到相遇
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

             // 相遇后，重新定义指针，再相遇
            if(slow == fast){
                 ListNode* index1 = head;
                 ListNode* index2 = fast;

                 while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                 }

                 return index1;
            }
        }

        return nullptr; // 这个要记得写
        
    }
};
// @lc code=end

// 笔记
// 1. 个人思路：遍历一遍，监测到有重复节点，则返回。
// 2. 这题也是找规律：快指针一次走两步；慢指针一次走一步。两者一定会相遇嘛？一定会，可以将其抽象为快指针追逐慢指针的问题，
//    比如两者差N开始追击，用T步同事到达，则 N + T = 2T, N = T，也就是说差几，用几步就能追上。
// 3. 慢指针是否会走完完整一圈才相遇：假设圈有X个节点，最多差X-1，根据上述推导T=X-1就会追上。

// 4. 下面为正式推导，假设走了X进圈，圈后走了Y相遇，剩下Z。那么可得 
//    2*(X+Y) = X + Y + (Y+Z)*N
//    X + Y = (Y + Z) N
//    X = (Y + Z) N - Y
//    X = (N - 1)(Y + Z) + Z
//    也就是说一个指针从 X 走，一个从 Z 走，两者一定会在圈入口点相遇

// 5. 判断条件下的返回，注意写全返回条件。

// 6. 指针为空的判断条件写了好几次，自己太死板了。

