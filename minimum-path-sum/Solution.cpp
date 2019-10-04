/**
 * 
 * https://leetcode.com/problems/minimum-path-sum/
 * 
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        const auto N = grid.size();
        const auto M = grid[0].size();
        
        for (auto i = 0u; i < N; ++i) {
            for (auto j = 0u; j < M; ++j) {
                if (i == 0 && j > 0) {
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                }
                else if (j == 0 && i > 0) {
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                }
                else if ( i > 0 && j > 0) {
                    grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        
        return grid[N - 1][M - 1];
    }
    
private:
};
