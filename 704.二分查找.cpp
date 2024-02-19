/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.empty())
            return -1;

        
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            cout << left << " " << right << math_errhandling;

            int middle = left + (right - left) / 2;

            if(nums[middle] > target)
                right = middle - 1;
            else if (nums[middle] < target)
                left = middle + 1;
            else
                return middle;
        }

        return -1;
        
    }
};
// @lc code=end

int main(){
    Solution x = Solution();
    vector<int> ilist = {-1,0,3,5,9,12};
    cout << x.search(ilist, 2) << endl;
    return 0;
}


// 笔记：
// 1. 二分查找：将问题拆分为子问题，递归解决
// 2. 除法：向下取整，所以在递归问题会向右判断
// 3. 参数检查
// 4. int的取值范围：4字节，32位，也就是2^31


