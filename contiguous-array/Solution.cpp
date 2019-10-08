/**
 * 
 * https://leetcode.com/problems/contiguous-array/
 * 
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const auto N = nums.size();
        unordered_map<int, int> counts;
        int ans = 0, count = 0;
        
        for (size_t i = 0; i < N; ++i) {
            count += nums[i]? 1 : -1;
            
            if (count == 0)
                ans = max(ans, int(i + 1));
            else if (auto it = counts.find(count); it != counts.end()) {
                ans = max(ans, int(i - it->second));
            }
            else
                counts[count] = i;
        }
        
        return ans;
    }
};
