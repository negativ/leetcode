/**
 * 
 * https://leetcode.com/problems/maximum-swap/
 * 
 */

class Solution {
public:
    int maximumSwap(int num) {
        using std::swap;
        
        auto s = to_string(num);
        
        size_t d[10] = {0};
        
        for (size_t i = 0; i < s.size(); ++i)
            d[s[i] - '0'] = i;
        
        for (size_t i = 0; i < s.size(); ++i) {
            auto x = s[i] - '0';
            
            for (size_t j = 9; j > 0 && j > x; --j) {
                if (i < d[j]) {
                    swap(s[i], s[d[j]]);
                    
                    return std::stoi(s);
                }
            }
        }
        
        return num;
    }
};
