/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:

    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }

        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                return mid;
            }

            if(nums[0] <= nums[mid]){ // 升序
                if(nums[0] <= target && target < nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(nums[mid] < target && target <= nums.back()){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

int main(){
    Solution x = Solution();
    vector<int> ilist = {4,5,6,7,0,1,2};
    cout << x.search(ilist, 3) << endl;
    return 0;
}

// 1. 二分
// 2. 找到递增序列，如果目标在这个区间里面，去找；如果目标不在这个区间里面，去右边找。
// 笔记：mid是有可能和元素相等的

