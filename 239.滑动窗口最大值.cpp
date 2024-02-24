/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include<string>
#include<stack>
#include<vector>
#include<deque>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
private:
    class MyQueue{
        public:
            deque<int> que;

            void pop(int value){
                if(!que.empty() && que.front() == value){
                    que.pop_front();
                }
            }

            void push(int value){
                while(!que.empty() && value > que.back()){
                    que.pop_back();
                }

                que.push_back(value);
            }

            int front(){
                return que.front();
            }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // 参数检验
        vector<int> result;
        if(nums.size() < k){
            return result;
        }

        MyQueue que;
        for(int i = 0; i < k ; ++i){
            que.push(nums[i]);
        }
        result.push_back(que.front());

        // 指针表示窗口末尾，pop,push,front
        for(int j = k; j < nums.size(); ++j){
            que.pop(nums[j-k]);
            que.push(nums[j]);
            result.push_back(que.front());
        }

        // return
        return result;
    }
};
// @lc code=end

int main(){
    Solution x = Solution();
    vector<int> ilist = {1,3,-1,-3,5,3,6,7};
    x.maxSlidingWindow(ilist,3);
    return 0;
}

// 笔记：
// 1. 单调队列
// 2. 新建类要加“;”
// 3. deque;