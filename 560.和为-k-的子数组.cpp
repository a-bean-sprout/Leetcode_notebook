/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;


// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 参数检验
        if(nums.empty()){
            return 0;
        }

        // 常规思路：此时时间复杂度是O(n^2)
        // for(int i = 0; i < nums.size(); ++i){
        //     int sum = 0;
        //     for(int j = i; j < nums.size(); ++j){  // [i,j] 内的和

        //     }
        // }

        // 前缀和思想：presum[i] - presum[j] == k , i > j

        // hash怎么用呢？ 将一个遍历搜索的O(n)操作，转化为O(1)的操作

        unordered_map<int, int> presum_count_map;
        presum_count_map[0] = 1;

        int presum = 0;
        int result = 0;
        for(int i = 0; i < nums.size(); ++i){

            presum += nums[i];

            if(presum_count_map.count(presum-k)){
                result += presum_count_map[presum-k];
            }

            presum_count_map[presum]++;
        }

        return result;
    }
};
// @lc code=end

