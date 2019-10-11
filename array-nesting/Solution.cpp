/**
 * 
 * https://leetcode.com/problems/array-nesting/
 * 
 */

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        const auto N = nums.size();
        vector<bool> visited(N, false);
        auto ans = 0;
        
        for (size_t n = 0; n < N; ++n) {
            if (visited[n])
                continue;
            
            auto x = nums[n];
            auto count = 0;
            
            do {
                visited[x] = true;
                x = nums[x];
                count++;
            } while (x != nums[n]);
                     
            ans = max(ans, count);
        }
        
        return ans;
    }
};

