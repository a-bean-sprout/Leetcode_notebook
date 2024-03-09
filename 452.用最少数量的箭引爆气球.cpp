/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include<vector>
using namespace std;



// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()){
            return 0;
        }

        sort(points.begin(), points.end(), cmp);

        int result = 1;
        for(int i = 1 ; i < points.size(); ++i){
            if(points[i][0] > points[i-1][1]){
                result++;
            }else{
                points[i][1] = min(points[i-1][1], points[i][1]);
            }
        }

        return result;
    }
};
// @lc code=end

