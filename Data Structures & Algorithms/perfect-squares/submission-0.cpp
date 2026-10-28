class Solution {
public:
    int numSquares(int n) {
        std::vector<int> memo(n+1, INT_MAX);
        memo[0] = 0;
        memo[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (i - j * j >= 0) {
                    memo[i] = std::min(memo[i], 1 + memo[i - j*j]);
                }
            }
        }
        return memo[n];

    }
};

