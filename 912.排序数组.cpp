/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
    void quickSort(vector<int>& nums, int left, int right){
        // 递归出口
        if(left >= right){
            return;
        }

        // 中
        int swap_index = left;
        for(int i = left; i < right; ++i){
            if(nums[i] < nums[right]){
                swap(nums[i], nums[swap_index]);
                swap_index++;
            }
        }
        swap(nums[swap_index], nums[right]);

        // 左
        quickSort(nums, left, swap_index -1);
        
        // 右
        quickSort(nums, swap_index+1, right);

        // 返回
        return;
    }

    void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp){
        // 递归出口
        if(left >= right){
            return;
        }

        int mid = (left + right) / 2;
        
        // 左
        mergeSort(nums,left,mid, temp);

        // 右
        mergeSort(nums,mid+1,right, temp);

        // 中
        int i = left, j = mid + 1;
        int index = left;
        while(i <= mid && j <= right){
            if(nums[i] < nums[j]){
                temp[index++] = nums[i++];
            }else{
                temp[index++] = nums[j++];
            }
        }

        while(i <= mid){
            temp[index++] = nums[i++];
        }

        while(j <= right){
            temp[index++] = nums[j++];
        }

        nums = temp;
        
        // 返回
        return;
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        // 参数检验
        if(nums.empty()){
            return {};
        }

        // 递归
        // quickSort(nums, 0, nums.size()-1);

        vector<int> temp = nums;
        mergeSort(nums, 0, nums.size()-1, temp);

        // 返回
        return nums;
    }
};
// @lc code=end

// 笔记：
// 快排：
//    1.快排到思路其实很简单，其实就是树结构，分而治之。
//    2.随机取一个元素，作为index，然后把小的元素放到左边，大的元素放在右边。
// 归排：
//    1.归并排序的思路也是树结构，只不过是左右中
//    2.
