/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

#include<vector>
#include<iostream>
using namespace std;


// @lc code=start
class Solution {
    vector<int>& nums;
public:
    Solution(vector<int>& nums):nums(nums){
    }
    
    int pick(int target) {
        int result;

        int count = 0;
        for(int i = 0 ; i < nums.size(); ++i){
            if(nums[i] == target){
                if(random() % ++count == 0){
                    result = i;
                }
                // 1/k * k/k+1 * k+1/k+2 ... = 1/n
            }
        }

        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

int main(){
    vector<int> temp = {1,2,3,3,3};

    Solution* s = new Solution(temp);
    cout << s->pick(1) << endl;
}

