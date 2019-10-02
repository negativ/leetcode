/**
 * 
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 * 
 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int l = 0, r = 0;
        int sum = 0;
        int minD = numeric_limits<int>::max();
        bool calculated = false;

        for (; r < nums.size(); ++r) {
            sum += nums[r];

            while (sum >= s && l <= r) {
                minD = min(minD, r - l + 1);
                sum -= nums[l];

                ++l;
                calculated = true;
            }
        }

        return calculated? minD : 0;
    }
};
