/**
 * 
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * 
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        
        return findMin(nums, 0u, nums.size());
    }
    
private:
    int findMin(vector<int>& nums, size_t l, size_t r) noexcept {
        if (r - l <= 1)
            return nums[l];
        
        if (nums[l] < nums[r - 1])
            return nums[l];
        
        auto d = (r - l) / 2;
        
        return min(findMin(nums, l, l + d),
                   findMin(nums, l + d, r));
    }
};