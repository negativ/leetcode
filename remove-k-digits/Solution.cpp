/**
 * 
 * https://leetcode.com/problems/remove-k-digits/
 * 
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.empty() || k >= num.size())
            return "0";
        
        const auto N = num.size();
        deque<char> q;
        
        for (size_t i = 0; i < N; ++i) {
            while (k > 0 && !q.empty() && q.back() > num[i]) {
                --k;
                q.pop_back();
            }
            
            q.push_back(num[i]);
        }
        
        while (k > 0)
            q.pop_back(), --k;
        
        while (q.size() > 1 && q.front() == '0')
            q.pop_front();
        
        string r;
        
        copy(begin(q), end(q), back_inserter(r));
        
        return r;
    }
};