/**
 * 
 * https://leetcode.com/problems/simplify-path/
 * 
 */

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathStack = move(split(path, '/'));
        deque<string> result;

        for (const auto& d : pathStack) {
            if (d.empty() || d == ".")
                continue;
            else if (d == "..") {
                if (!result.empty())
                    result.pop_back();
            }
            else
                result.push_back(d);
        }

        if (result.empty())
            return "/";

        return accumulate(result.begin(), result.end(),
                          string{""},
                          [](auto path, auto d) {return std::move(path + "/" + d); });
    }

    vector<string> split ( const string& s, char delim ) {
        vector<string> tokens;
        tokens.reserve(2);

        auto l = 0u, r = 0u;
        
        for (auto c : s) {
            if (c != delim)
                ++r;
            else {
                if (r - l > 0)
                    tokens.emplace_back(move(s.substr(l, r - l)));
                ++r;
                
                l = r;
            }
        }
        
        if (r - l > 0)
            tokens.emplace_back(move(s.substr(l, r - l)));
        
        return tokens;
    }
};
