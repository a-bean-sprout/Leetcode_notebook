/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:

    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {

        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};
// @lc code=end

// 思路：
// 问题：找第K小的元素，
//      当总个数为奇数时，K = (nums1.size()+nums2.size()) / 2 + 1;
//      当总个数为偶数时，K1 = (nums1.size()+nums2.size()) / 2， K2 =  (nums1.size()+nums2.size()) / 2 + 1
//      注意上述思路中，K为个数而不是索引

// 取两个数组大小为 2/k - 1的索引，那么对于两者的最小值，最多最多有k - 2个元素比它小，再加其本身 k - 1个元素
// 所以整个可以排除法，也就是类似二分搜索的思想



