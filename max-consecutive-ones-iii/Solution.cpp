/**
 * 
 * https://leetcode.com/problems/max-consecutive-ones-iii/
 * 
 */

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        const auto N = A.size();
        
        auto l{0}, r{0}, ans{0};
        
        while(r < N){
            if(A[r] == 1){
                ++r;
                ans = max(ans, r - l);
            }
            else{
                if(K != 0){
                    --K;
                    ++r;
                    ans = max(ans, r - l);
                }
                else {
                    if(A[l] == 0)
                        ++K;
                    ++l;
                }
            }
        }
        
        return ans;
    }
};
