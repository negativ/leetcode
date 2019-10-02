/**
 * 
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/
 * 
 */

class Solution {
    struct Edge {
        int id{0};
        int cost{0};
        int order{-1};
        
        bool operator>(const Edge& rhs) const { return cost > rhs.cost; }
    };
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        using Edges = std::vector<Edge>; // cache-friendly container
        using Graph = unordered_map<int, Edges>;
        Graph graph;
        
        for (const auto& v : flights)
            graph[v[0]].push_back({v[1], v[2], 0});
        
        queue<Edge> q;
        
        q.push({src, 0, -1});
        auto min_cost = numeric_limits<int>::max();
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            const auto& edges = graph[current.id];
            
            for (const auto& e : edges) {
                auto cost = e.cost + current.cost;
                
                if (current.order == K || cost >= min_cost) 
                    continue;
                
                if (e.id == dst && cost < min_cost)
                    min_cost = cost;
                else
                    q.push({e.id, cost, current.order + 1});
            }
        }
        
        if (min_cost == numeric_limits<int>::max())
            return -1;
        
        return min_cost;
    }
}; 
