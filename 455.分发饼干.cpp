/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 参数检验

        // 排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // 贪心算法
        int result = 0;
        for(int i = s.size()-1, index = g.size() -1; i >=0 && index >=0; --i, --index){
            while(index >= 0 && s[i] < g[index]){
                index --;
            }
            if(index < 0){
                break;
            }
            result++;
        }

        // 返回
        return result;
    }
};
// @lc code=end

