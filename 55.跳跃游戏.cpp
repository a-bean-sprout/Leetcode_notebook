/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:

    bool canJump(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return false;
        }

        // 贪心
        int cover = 0;  // 能达到的索引
        for(int i = 0; i < nums.size(); ++i){
            if(i > cover){
                break;
            }
            
            cover = max(i+nums[i], cover);

            if(cover >= nums.size() - 1){
                return true;
            }
        }

        // 返回
        return false;
    }
};
// @lc code=end

// 这个题很妙，实际上求的是覆盖范围。写起来也很妙，截止条件动态变化的题，第一次遇到

