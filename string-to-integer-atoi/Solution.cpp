/**
 * 
 * https://leetcode.com/problems/string-to-integer-atoi/
 * 
 */

class Solution {
public:
    int myAtoi(string str) {
        bool overflow{false};
        int sign = 1;
        int result = 0;
        bool signset = false;
        
        auto start = begin(str), stop = end(str);
        
        while (start != stop) {
            if (*start == ' ') {
                ++start;
                
                continue;
            }
            else if (isdigit(*start)) {
                break;
            }
            else if (*start == '-'){
                if (signset)
                    return 0;
                
                signset = true;
                sign = -1;
                ++start;
                
                break;
            }
            else if (*start == '+') {
                if (signset)
                    return 0;
                
                signset = true;
                ++start;
                
                break;
            }
            else
                return 0;
            
            ++start;
        }
        
        while (start != stop && isdigit(*start)) {
            auto x = digit_to_num(*start);
            auto y = result * 10;
            
            if (mul_overflow(result, 10) ||
                sum_overflow(y, x)) {
                overflow = true;
                break;
            }
            
            result = y + x;           
            
            ++start;
        }
        
        if (overflow)
            return (sign < 0)? numeric_limits<int>::min() : numeric_limits<int>::max();
        
        return sign * result;
    }
    
private:
    // would work only for positive ints!
    bool sum_overflow(int a, int b) {
        return (a > (numeric_limits<int>::max() - b));
    }
                
    bool mul_overflow(int a, int b) {
        return (a > (numeric_limits<int>::max() / b));
    }
    
    int digit_to_num(char a) {
        return a - '0';
    }
};
