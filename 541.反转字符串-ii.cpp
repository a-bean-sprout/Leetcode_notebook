/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {

        // 参数检验

        // [0,k)反转，[k,2k)不反转
        for(int i =0; i <s.size(); i = i+2*k){
            
            if(i + k < s.size()){
                reverse(s.begin()+i,s.begin()+i+k);
            }else{
                reverse(s.begin()+i,s.end());
            }
        }

        return s;

    }
};
// @lc code=end

