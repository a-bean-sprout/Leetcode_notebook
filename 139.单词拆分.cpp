/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include<string>
#include<set>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 参数检验

        // 完全背包问题
        vector<bool> dp(s.size()+1, false);

        dp[0] = true;

        set<string> wordSet(wordDict.begin(), wordDict.end());

        for(int i = 1; i < dp.size(); ++i)  {  // i 表示 [1-i]个元素/背包
            for(int j = 0; j < wordDict.size(); ++j){  // j 表示 [1-j]个物品
                if(wordDict[j].size() <= i){
                    string str = s.substr(i - wordDict[j].size(), wordDict[j].size());   // 这里 s 容易错，需要注意
                    cout << str << endl;

                    if(wordDict[j] == str && dp[i-wordDict[j].size()]){
                        dp[i] = true;
                    }

                    cout << i <<"," << j << ":" << dp[i] << endl;;
                }
            }
        }
        
        return dp.back();
    }
};
// @lc code=end

// 笔记：
// 这道题用背包问题做，很奇怪呀。
// 给定一个字符串 s 和一个组合，求是否s可以由组合内元素拼接而成

// j表示从[1-j]个元素，能否被[1-i]的物品表示。
// dp[i][j] = (dp[i-1][j] || dp[i][j-i.size])
// dp[j] = dp[i] || dp[j-i.size]
// 其实也就是当 dp[j-i.size] 时，赋值。

int main(){
    Solution x = Solution();
    string s = "leetcode";
    vector<string> ilist = {"leet", "code"};
    x.wordBreak(s, ilist);
    return 0;
}


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
