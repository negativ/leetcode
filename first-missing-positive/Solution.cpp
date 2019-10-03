/**
 * 
 * https://leetcode.com/problems/first-missing-positive/
 * 
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::vector<bool> present(nums.size(), false);
        
        for (auto x : nums)
            if (x > 0 && x <= nums.size())
                present[x - 1] = true;
        
        for (size_t i = 0; i < present.size(); ++i)
            if (!present[i])
                return i + 1;
        
        return present.size() + 1;
    }
};
