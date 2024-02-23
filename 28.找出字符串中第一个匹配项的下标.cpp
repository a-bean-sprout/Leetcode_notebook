/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {

    }
};
// @lc code=end
// 笔记
// 判断是否是子串，需要逐一匹配的。
// KMP算法
// 背景：通常判断一个字符串是否包含子串，是需要逐一匹配的，也就是需要双重循环。KMP算法的本质是在循环时做好不匹配的准备，记录子串前缀

