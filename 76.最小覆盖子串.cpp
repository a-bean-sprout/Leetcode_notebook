/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // 参数检验
        if(s.empty() || t.empty()){
            return "";
        }

        // 验证结果：字符个数相等
        unordered_map<char, int> targetMap, curMap;
        for(auto c: t) targetMap[c]++;
        int valueNum = 0;

        // 结果存储
        int res_begin = -1, len = INT_MAX;

        int left =0, right = 0;  
        // 双指针法：滑动串口, [left, right)，意思就是right指向待处理的元素
        while(right < s.size()){

            cout << "right:" << right << endl;
            char cur = s[right++];
            
            // 更新计数，为判断是否达成目标做准备
            if(targetMap.count(cur)){
                curMap[cur]++;

                if(curMap[cur] == targetMap[cur]){
                    valueNum++;
                }
            }

            // 缩小窗口
            while(valueNum == targetMap.size()){
                // 记录结果
                if(len > right - left){
                    len = right - left;
                    res_begin = left;
                }

                cout << "left:" << left << endl;
                char drop_cur = s[left++];

                // 更新计数
                if(targetMap.count(drop_cur)){
                    curMap[drop_cur]--;

                    if(curMap[drop_cur] < targetMap[drop_cur]){
                        valueNum --;
                    }
                }
                
            }
        }

        if(res_begin != -1){
            return s.substr(res_begin, len);
        }

        return "";

    }
};
// @lc code=end

int main(){
    Solution x = Solution();
    string s = "aab", t = "aab";
    cout << x.minWindow(s,t) << endl;
    return 0;
}



// 题目：t是小串了，从s里找最小的小串

