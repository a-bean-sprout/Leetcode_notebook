/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include<stack>
#include<iostream>
using namespace std;

// @lc code=start
class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;

    MyQueue() {

    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        // 参数检验
        if(empty()){
            return -1;
        }

        // 判断是否outStack为空,更新outStack
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        int result = outStack.top();
        outStack.pop();

        return result;

    }
    
    int peek() {
        // 参数检查

         // 判断是否outStack为空,更新outStack
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        int result = outStack.top();

        return result;

        // 这里可以利用pop的逻辑简化
        // int res = this->pop(); 
        // stOut.push(res); 
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

// 笔记
// 栈：常用push/pop方法，即push(x)增至栈顶、pop()删除栈顶、top()取栈顶元素

// 调用类内自己的元素，可以使用this指针

