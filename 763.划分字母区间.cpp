/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 参数检查
        if(s.empty()){
            return {};
        }

        // 遍历字符串，得字符最远位置
        int hash[26] = {};
        for(int i = 0 ; i < s.size(); ++i){
            hash[s[i] - 'a'] = i;
        }

        // 遍历字符串，计算串口
        int left = 0;
        int right = 0;
        vector<int> res;
        for(int i = 0; i < s.size(); ++i){
            right = max(right, hash[s[i] - 'a']);

            if(i == right){
                res.push_back(right - left + 1);
                left = right + 1;
            }
        }

        // 结果返回
        return res;
    }
};
// @lc code=end

