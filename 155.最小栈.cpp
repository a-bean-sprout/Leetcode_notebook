/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include<stack>
using namespace std;

// @lc code=start
class MinStack {
public:
    stack<int> x_st;
    stack<int> min_st;
    MinStack() {
        min_st.push(INT_MAX);
    }
    
    void push(int val) {
        x_st.push(val);
        min_st.push(min(min_st.top(), val));
    }
    
    void pop() {
        x_st.pop();
        min_st.pop();
    }
    
    int top() {
        return x_st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

