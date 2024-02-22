/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        // 参数检查
        if(nums1.empty()){
            return 0;
        }

        // 双循环，更新Map<sum,count>
        unordered_map<int,int> sumCount_map;
        for(int &num1:nums1){
            for(int &num2:nums2){
                sumCount_map[num1+num2]++;
            }
        }

        int count = 0;
        // 双循环，查找map，更新count
        for(int &num3:nums3){
            for(int &num4:nums4){
                if(sumCount_map.find(-(num3+num4))!=sumCount_map.end()){
                    count += sumCount_map[-(num3+num4)];
                }
            }
        }

        return count;
    }
};
// @lc code=end

// 暴力枚举：N*4
// 暴力枚举 + Hash : N*3 + LogN
// 不如拆成两个 2N + Hash 

