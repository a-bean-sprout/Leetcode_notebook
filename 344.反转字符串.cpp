/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        
        // 参数检查
        if(s.empty()){
            return;
        }

        // for循环，双指针交换元素
        // for(int i =0; i < s.size()/2; ++i){
        //     swap(s[i],s[s.size()-1-i]);
        // }
        for(int i = 0, j = s.size()-1; i <j ; i++,j--){
            swap(s[i],s[j]);
        }

        return;
    }
};
// @lc code=end

// 笔记
// 

