/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        // 参数检验
        if(nums.empty() || nums.size() == 1){
            return 0;
        }

        // 更新最大范围
        int nextDistence = 0;
        int count = 0;
        int curDistence = 0;
        for(int i = 0 ; i < nums.size(); ++i){

            nextDistence = max(i + nums[i], nextDistence);

            // 当遍历当某步
            if(i == curDistence){
                curDistence = nextDistence;
                count ++;
                if(curDistence >= nums.size() -1){
                    return count;
                }
            }
        }

        // 返回
        return -1;
    }
};
// @lc code=end

