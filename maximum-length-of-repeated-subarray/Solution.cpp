/**
 * 
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/
 * 
 */

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> AB(A.size() + 1, vector<int>(B.size() + 1, 0));
        auto ans = 0;
        
        for (int i = A.size() - 1; i >= 0; --i)
            for (int j = B.size() - 1; j >= 0; --j)
                if (A[i] == B[j]) {
                   AB[i][j] = AB[i + 1][j + 1] + 1;
                   ans = max(AB[i][j] , ans);
                }
        
        return ans;
    }
};
