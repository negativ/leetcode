/**
 * 
 * https://leetcode.com/problems/ransom-note/
 * 
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.empty() && magazine.empty())
            return true;
        
        unordered_map<char, size_t> mchars;
        
        for (auto c : magazine)
            ++mchars[c];
        
        for (auto c : ransomNote) {
            auto it = mchars.find(c);
            
            if (it == end(mchars))
                return false;
            
            if (it->second == 1)
                mchars.erase(it);
            else
                --it->second;
        }
        
        return true;
    }
};
