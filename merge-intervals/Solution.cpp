/**
 * 
 * https://leetcode.com/problems/merge-intervals/
 * 
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals.front().empty())
            return {};
        
        sort(begin(intervals), end(intervals),
             [](auto&& x, auto&& y) { return x[0] < y[0]; });
        
        const auto N = intervals.size();
        size_t p = 0;
        
        for (size_t i = 0; i < N; ++i) {
            if (intervals[i][0] <= intervals[p][1])
                intervals[p][1] = max(intervals[p][1], intervals[i][1]);
            else {
                if (++p < i) // do not move item to themself
                    intervals[p] = std::move(intervals[i]);
            }
                
        }
        
        intervals.resize(p + 1); // remove tail with invalid data
        intervals.shrink_to_fit(); // returning free data to allocator
        
        return intervals;
    }
};
