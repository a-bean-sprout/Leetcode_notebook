/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 题目：判断 m 内元素能不能构成 r，并且只能使用一次

        // 参数检验
        if(magazine.empty() || magazine.size() < ransomNote.size()){
            return false;
        }

        // 将M中元素存储至数组
        int count_array[26] = {0};
        for(int i = 0; i < magazine.length(); ++i){
            count_array[magazine[i]-'a']++;
        }

        // 遍历 R ，命中后修改数组
        for(int j = 0; j < ransomNote.length(); ++j){
            count_array[ransomNote[j]-'a']--;

            if(count_array[ransomNote[j]-'a'] < 0){
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
// 笔记：
// 个人思路：遍历 R 中元素，命中 M 中元素后擦除，如果能遍历结束，那么返回True。
// 当然遍历 M 也可以。

// 数组的定义方式



