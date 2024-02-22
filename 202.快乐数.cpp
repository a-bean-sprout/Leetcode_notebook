/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:

    int getSum(int n){
        int sum = 0;
        
        while(n){
            sum += (n % 10) * (n % 10);
            n = n / 10; // 简化写法 n /= 10；
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sum_set;

        int sum = getSum(n);
        while(sum != 1){

            if(sum_set.find(sum) != sum_set.end()){
                return false;
            }

            sum_set.insert(sum);
            sum = getSum(sum);

        }

        return true;
    }
};
// @lc code=end

// 笔记
// 1. 规律：若迭代过程出现出现循环，那返回Flase