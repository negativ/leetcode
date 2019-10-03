/**
 * 
 * https://leetcode.com/problems/toeplitz-matrix/
 * 
 */

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty())
                    return false;

                for (size_t M = 1; M < matrix.size(); ++M) {
                    for (size_t N = 1; N < matrix[M].size(); ++N)
                        if (matrix[M - 1][N - 1] != matrix[M][N])
                            return false;
                }

                return true;
    }
};
