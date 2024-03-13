/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include<vector>
#include<unordered_map>
using namespace std;


// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = nullptr;
//         random = nullptr;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 参数检验

        // 构建链表，并及时存储映射关系
        unordered_map<Node*, Node*> newOld_map;

        Node* cur = head;
        while(cur){
            Node* New = new Node(cur->val);
            newOld_map[cur] = New;
            cur = cur->next;
        }

        cur = head;
        while(cur){
            newOld_map[cur]->next = newOld_map[cur->next];
            newOld_map[cur]->random = newOld_map[cur->random];
            cur = cur->next;
        }

        return newOld_map[head];
    }
};
// @lc code=end

// 链表循环的理解。

