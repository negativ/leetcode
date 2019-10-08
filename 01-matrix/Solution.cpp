/**
 * 
 * https://leetcode.com/problems/01-matrix
 * 
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        
        const auto N = matrix.size();
        const auto M = matrix[0].size();
        
        auto r = vector<vector<int>>(N, vector<int>(M, numeric_limits<int>::max() - 1));
        
        for (size_t i = 0u; i < N; ++i) {
            for (size_t j = 0u; j < M; ++j) {
                if (matrix[i][j] == 0)
                    r[i][j] = 0;
                else {
                    if (i > 0)
                        r[i][j] = min(r[i - 1][j] + 1, r[i][j]);
                    if (j > 0)
                        r[i][j] = min(r[i][j - 1] + 1, r[i][j]);
                }
            }
        }
        
        for (size_t i = N - 1; i < N; --i) {
            for (size_t j = M - 1; j < M; --j) {
                if (matrix[i][j] == 0)
                    r[i][j] = 0;
                else {
                    if (i != N - 1)
                        r[i][j] = min(r[i + 1][j] + 1, r[i][j]);
                    if (j != M - 1)
                        r[i][j] = min(r[i][j + 1] + 1, r[i][j]);
                }
            }
        }
        
        return r;
    }
};
