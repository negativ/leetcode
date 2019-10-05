/**
 * 
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 * 
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        
        return search(nums, 0u, nums.size(), target);
    }

private:
    int search(vector<int>& nums, size_t l, size_t r, int target) noexcept {
        if (r - l == 1)
            return nums[l] == target? l : -1;
        
        auto d = (r - l) / 2;
        auto lv = nums[l];
        auto rv = nums[r - 1];
        auto dv = nums[l + d];
        
        if (lv < rv) { // do ordinary binary search
            if (target < lv || target > rv)
                return -1;
            
            if (target == dv)
                return l + d;
            else if (target < dv)
                return search(nums, l, l + d, target);
            else
                return search(nums, l + d, r, target);
        }
        
        return max(search(nums, l, l + d, target),
                   search(nums, l + d, r, target));
    }
};