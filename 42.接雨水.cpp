/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include<vector>
#include<stack>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 参数检验
        if(height.size() <= 2){
            return 0;
        }

        stack<int> st;
        st.push(0);  // 存放索引

        int sum = 0;
        for(int i = 1; i < height.size(); ++i){
            if(height[i] < height[st.top()]){
                st.push(i);
            }else if(height[i] == height[st.top()]){
                st.pop();
                st.push(i);
            }else{

                while(!st.empty() && height[i] > height[st.top()]){
                    int mid_index = st.top();
                    st.pop();

                    if(!st.empty()){
                        int x = min(height[i], height[st.top()]) - height[mid_index];
                        int y = i - st.top() - 1;

                        sum += (x * y);
                    }
                }

                st.push(i);
            }

        }

        return sum;

    }
};
// @lc code=end


// 接雨水
// 给定非负整数表示柱子高度，求柱子间能接到的雨水
// 思路：
// 如果按列计算：单位列能聚集的水量 = diff(左边最高的元素 - 右边最高的元素）

// 本质是单调栈的应用：找第一个比它大或者小的元素

