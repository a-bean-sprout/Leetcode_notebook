/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtraceing(int startIndex, int n, int k){
        // 递归截止
        if(path.size() == k){ 
            result.push_back(path);
            return;
        }

        // 遍历子节点，递归
        for(int i = startIndex; i < n && n - i >= k - path.size(); ++i){
            path.push_back(i+1);
            backtraceing(i+1,n,k);
            path.pop_back(); // 这里回溯：准备进入节点的另一个分支
        }

        // 返回
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        // 参数检验
        if( k > n){
            return {};
        }

        // 递归逻辑
        backtraceing(0, n, k);

        // 返回
        return result;
    }
};
// @lc code=end

// 笔记
// 背景：
// 1. 题目：给定一个数组，返回任意k个数的组合
// 2. 解法：典型的多重循环遍历问题，需要几个数的组合，就需要几层循环。为了防止重复，会往前取。
// 3. 但是如果k过多，那么for循环写起来就很不方便了，所以需要用到回溯

// 回溯：
// 1. 回溯的结构
//  void backtracking(参数){
//     if(终止条件){
//         存放结果；
//         return;
//     }

//     for(选择：本层中集合元素){ // 树中孩子节点的数量
//         处理节点
//         递归：backtracking()
//         回溯
//     }
// }


// 还是要画图，空想太费劲了

// 数组索引的理解：索引是几，表明其前面有几个元素。
