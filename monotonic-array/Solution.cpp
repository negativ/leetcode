/**
 * 
 * https://leetcode.com/problems/monotonic-array/
 * 
 */

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.empty())
            return false;
        
        auto increasing = true,
             decreasing = true;
        
        const auto N = A.size();
        
        for (size_t i = 1; i < N && (increasing || decreasing); ++i) {
            increasing &= A[i - 1] <= A[i];
            decreasing &= A[i - 1] >= A[i];
        }
        
        return increasing || decreasing;
    }
};
