/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> result_set;
        set<int> nums_set(nums1.begin(), nums1.end());

        // 遍历另一数组，判断是否在set内，若true插入
        for(int num : nums2){
            if(nums_set.find(num) != nums_set.end()){
                result_set.insert(num);
            }
        }

        return vector<int>(result_set.begin(), result_set.end());
    }
};
// @lc code=end

// 笔记
// 个人思路：遍历两个数组，把数组元素存到et里即可
// set结构常用两种：unordered_set 和 set，前者无序方便增减，后者有序便于查询
// 注意熟悉set和vector的相互转化

