/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 参数检验
        if(s.empty() || p.empty()){
            return {};
        }

        unordered_map<char, int> curMap, targetMap;
        for(auto c: p) targetMap[c]++;

        // 滑动窗口
        int left = 0, right = 0;

        int resCount = 0;
        vector<int> res;
        while(right < s.size()){
            char cur = s[right++];

            if(targetMap.count(cur)){
                curMap[cur]++;
                if(curMap[cur] == targetMap[cur]){
                    resCount++;
                }
            }

            // 判断收缩
            while(right - left >= p.size()){
                if(resCount == targetMap.size() && right - left == p.size()){
                    res.push_back(left);
                }

                char drop_char = s[left++];

                if(targetMap.count(drop_char)){
                    if(curMap[drop_char] == targetMap[drop_char]){
                        resCount--;
                    }

                    curMap[drop_char]--;
                }
            }
        }
        
        // 返回
        return res;
    }
};
// @lc code=end

