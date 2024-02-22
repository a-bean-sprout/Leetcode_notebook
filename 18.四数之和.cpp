/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> res;

        // 参数检查
        if(nums.size() < 4){
            return res;
        }

        // 排序
        sort(nums.begin(),nums.end());

        // 遍历元素双指针
        for(int i = 0; i <nums.size(); ++i){
            
            // 这里特别容易错
            // 或者可直接理解：当小数为正数时，只有后面的比目标大，就不可能了
            // ------- 以下为繁琐理解 -------------
            // 四个小数相加得大数，并不是最小数 > 大数，就绝对不可能相加
            // 大数为负数时，是可以由大于它的数相加得到的
            // 也就是说：
            // 1. 当大数为正数，小数大于大数时，不成立
            // 2. 当大数为负数时，小数可以大于大数，但当小数 >0时，不成立
            // if(nums[i] > target && (target >=0 || nums[i] >=0)){
            //     break;
            // }

            // 最后可化简为
            if(nums[i] > target && nums[i] >= 0){
                break;
            }

            // i去重
            if( i>0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j = i+1; j <nums.size(); ++j){

                // 这里也特别容易错
                if(nums[i]+nums[j] > target && nums[i]+nums[j] >= 0){
                    break;
                }

                // j去重
                if(j > i+1 & nums[j] == nums[j-1]){
                    continue;
                }

                int left = j+1;
                int right = nums.size()-1;

                while(left < right){
                    // 加法可能会被溢出
                    if((long)nums[i]+nums[j]+nums[left]+nums[right] < target){
                        left++;
                    }else if((long)nums[i]+nums[j]+nums[left]+nums[right] > target){
                        right--;
                    }else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        while(left < right && nums[left] == nums[left+1]){
                            left++;
                        }

                        while(left < right && nums[right] == nums[right-1]){
                            right--;
                        }

                        left++;
                        right--;
                    }
                    
                }
            }
        }

        return res;
    }
};
// @lc code=end

// 笔记：
// 1. 四数之和是三数之和的升级版，三数之和的思想是双指针。大概就在三数之和外套一层循环
// 注意：
// 1. 剪枝的条件：当小数为正数时，只有后面的比目标大，就不可能了
// 2. 加法溢出