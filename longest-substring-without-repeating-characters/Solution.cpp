/**
 * 
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * 
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto p = max_uniq(begin(s), end(s));
        
        return distance(p.first, p.second);
    }
    
    template <typename Iterator, typename Value = typename std::iterator_traits<Iterator>::value_type>
    std::pair<Iterator, Iterator> max_uniq(Iterator start, Iterator stop) {
        std::set<Value> found;

        auto l = start, r = start,
             ml = start, mr = start; // max left/right iterators

        auto md = std::abs(std::distance(ml, mr));

        while (l != stop && r != stop) {
            auto it = found.find(*r);

            if (it == std::end(found)) {
                found.insert(*r++);

                auto d =  std::abs(std::distance(l, r));

                if (d > md) {
                    ml = l;
                    mr = r;
                    md = d;
                }
            }
            else
                found.erase(*l++);
        }

        return {ml, mr};
    }
    
};
