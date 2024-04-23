/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

#include<unordered_map>
using namespace std;



// @lc code=start
class LRUCache {
private:
    struct DLinkedNode{
        int val;
        int key;  // 便于溢出时在Map中删除Key
        DLinkedNode* next;
        DLinkedNode* pre;
        DLinkedNode():val(0),key(0),next(nullptr),pre(nullptr){}
        DLinkedNode(int key, int val):val(val),key(key),next(nullptr),pre(nullptr){}
    };
    unordered_map<int, DLinkedNode*> keyNodeMap;
    DLinkedNode* head; 
    DLinkedNode* tail; // 因为按照使用顺序排序，因此需要在链表尾部删，在头部减，因此建立两个指针快速到达
    int _size;
    int _capacity;
    
public:
    LRUCache(int capacity):_capacity(capacity), _size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
    }

    void removeNode(DLinkedNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addToHead(DLinkedNode* node){
        node->pre = head;
        node->next = head->next;

        head->next->pre = node;
        head->next = node;
    }

    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }
    
    int get(int key) {
        // 返回关键字的值
        if(!keyNodeMap.count(key)){
            return -1;
        }

        // 移动至头部
        DLinkedNode* node = keyNodeMap[key];
        moveToHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        // 关键值不存在
        // 1. 插入至头部
        // 2. 判断是否插满。满则链表删除，并更新map
        if(!keyNodeMap.count(key)){
            DLinkedNode* node = new DLinkedNode(key, value);
            keyNodeMap[key] = node;

            addToHead(node);
            _size++;

            if(_size > _capacity){
                int deleteKey = tail->pre->key;
                keyNodeMap.erase(deleteKey);

                removeNode(tail->pre);
                _size--;
            }

            return;
        }

        // 关键值存在，修改，置头
        DLinkedNode* node = keyNodeMap[key];
        node->val = value;

        moveToHead(node);

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

// 笔记：
// 题目：key-value数据的存储问题
// 1. O(1)时间完成查询操作 int get()
// 2. O(1)时间完成插入/删除操作 void put()。删除最久未使用的关键字。

// 因此本题的数据结构是哈希链表

// 因此使用了链表与map的结合体，大概的数据结构是 <key, *DListNode>

// 为何使用双端链表：为了便于删除和插入节点，删除和插入操作要求对应节点的前一个节点
// 双端链表的存储需要多余存储一份key值，因为在数据结构溢出时，需要得到溢出数据在map中的key，以把他删掉。
