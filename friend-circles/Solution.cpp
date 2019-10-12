/**
 * 
 * https://leetcode.com/problems/friend-circles/
 * 
 */

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        const auto N = M.size();
        vector<bool> students(N, true);

        auto ans = 0;
        
        for (auto i = 0u; i < N; ++i) {
            if (!students[i])
                continue;
            
            ++ans;
            
            deque<int> q;
            q.emplace_back(i);
            
            while (!q.empty()) {
                auto student = q.back();
                q.pop_back();
                
                students[student] = false;
                
                const auto& friends = M[student];
                const auto S = friends.size();
                
                for (auto i = 0u; i < S; ++i) {
                    if (students[i] && friends[i] == 1)
                        q.emplace_back(i);
                }
            }
        }
        
        return ans;
    }
};
