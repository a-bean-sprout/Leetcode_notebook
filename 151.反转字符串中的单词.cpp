/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:

    void reverseString(string& s, int a, int b){
        // 参数检验
        if(s.empty()){
            return;
        }

        // swap
        //for(int i = a; i < (b - a)/2; ++i){
        //    swap(s[i],s[b-i+a]);
        //}

        // 上面这个写复杂了
        for(int i = a, j =b; i<j ; i++,j--){
            swap(s[i],s[j]);
        }
    }

    string reverseWords(string s) {

        // 参数检验
        if(s.empty()){
            return s;
        }

        // 空格删除
        int slowIndex = 0;
        for(int i =0; i<s.size(); ++i){
            if(s[i] != ' '){
                if(slowIndex != 0){
                    s[slowIndex++] = ' ';
                }
                while(i < s.size() && s[i] != ' '){
                    s[slowIndex++] = s[i]; 
                    ++i;
                    // 可简化为 s[slowIndex++] = s[i++]; 
                }
            }
        }

        s.resize(slowIndex);

        // 反转字符串
        reverseString(s, 0,s.size()-1);

        // 再次反转字符串
        // 其实这里可以用for循环而且更好
        // int begin = 0;
        // int end = 0;
        // while(end < s.size()){
        //     while(end < s.size() && s[end] != ' '){
        //         end++;
        //     }

        //     reverseString(s, begin, end-1);

        //     end++;
        //     begin = end;
        // }
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverseString(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }

        return s;
    }
};
// @lc code=end

// 笔记
// 1. 思路应该是反转再反转，反转其实
// 2. 数组删除的逻辑

