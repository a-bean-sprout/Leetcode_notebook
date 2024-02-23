/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include<queue>
using namespace std;

// @lc code=start
class MyStack {
public:

    queue<int> inQueue;
    queue<int> copyQueue;

    MyStack() {

    }
    
    void push(int x) {
        inQueue.push(x);
    }
    
    int pop() {
        // 参数检验

        // 复制至Copy队列，In队列留一个
        while(inQueue.size() != 1){
            copyQueue.push(inQueue.front());
            inQueue.pop();
        }

        // 弹出In队列
        int result = inQueue.front();
        inQueue.pop();

        // swap
        inQueue.swap(copyQueue);

        return result;
    }
    
    int top() {
        return inQueue.back();
    }
    
    bool empty() {
        return inQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

// 笔记：
// 队列：先入先出，栈：先入后出。现在用两个队列实现栈
// 思路：这个题不能用两个栈实现队列的思路。使用两个队列，其中一个队列单纯负责存储。

// stack的操作：back()、front()

