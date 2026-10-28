class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> memo(m, std::vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
            }
        }
        return memo[m - 1][n - 1];
    }
};