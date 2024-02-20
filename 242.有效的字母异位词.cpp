/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {

        // 参数检查
        if(s.length() != t.length()){
            return false;
        }

        // 遍历，存储至数组中
        int record[26] = {0};

        for(int i = 0; i < s.length(); ++i){
            record[s[i] - 'a']++;
        }

        for(int j = 0; j < t.length(); ++j){
            record[t[j] - 'a']--;
        }

        for(int k = 0; k < sizeof(record)/sizeof(record[0]); ++k){
            if(record[k] != 0){
                return false;
            }
        }

        return true;

    }
};
// @lc code=end

// 个人思路：
//    遍历两字符串，存储其字母和出现数，存在Map里，遍历两Map是否相等。
// 题解思路：
//    其实类似，只不过hash结构为数组

// 注意单引号和双引号的区别：单引号表示字符Char类型，双引号表示字符串
// C++无法直接获取数组长度，

