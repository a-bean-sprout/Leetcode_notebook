/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include<string>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    class MyCompare{
        public:
            bool operator()(const pair<int,int>& x, const pair<int,int>& y){
                return x.second > y.second;
            }
    }; 

    vector<int> topKFrequent(vector<int>& nums, int k) {

        // 参数检验
        if(nums.empty() && k <=0){
            return {};
        }

        // 遍历nums，计数存储为map结构
        unordered_map<int,int> num_map; 
        for(auto const &num : nums){
            num_map[num]++;
        }

        // 构建优先队列，对优先队列赋值
        priority_queue<pair<int,int>, vector<pair<int,int>>, MyCompare> pri_que;
        for(auto iter = num_map.begin(); iter != num_map.end(); ++iter){
            pri_que.push(*iter);

            if(pri_que.size() > k){
                pri_que.pop();
            }
        }


        // 将优先队列元素存为vector
        vector<int> result(k);
        for(int i = k-1; i >=0; --i){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }

        // 返回
        return result;
    }
};
// @lc code=end

// 个人思路：
// 1. 统计出现频率
// 2. 排序
// 3. 如果自己写的话，那么用Map是最好的。但如果你让我用栈和队列

// 思路：
// 1. 优化队列： priority_queue
// 2. 初始化方式：priority_queue<int, vector<int>, greater<int>> ，分别为数据类型、底层容器、比较器

// 比较：
// 1. 传统整体排序的复杂度是：nlogn
// 2. 优先队列的时间复杂度：nlogk

// 函数调用运算符的重载：函数名operator()
// 小顶堆的比较函数，正好和普通的相反。树的生成是从头节点开始的，大于则置后。

