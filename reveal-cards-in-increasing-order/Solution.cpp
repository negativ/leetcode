/**
 * 
 * https://leetcode.com/problems/reveal-cards-in-increasing-order/
 * 
 */

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const auto N = deck.size();
        
        deque<size_t> indexes(N);
        generate_n(begin(indexes), N, [n = N, N = N]() mutable { return N - (n--); });

        sort(begin(deck), end(deck));
        
        vector<int> ret(N);
        
        for (auto& card : deck) {
            ret[indexes.front()] = card;
            indexes.pop_front();
            
            if (!indexes.empty()) {
                indexes.push_back(indexes.front());
                indexes.pop_front();
            };
        }
        
        return ret;
    }
};
