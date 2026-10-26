class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> memo(n, 0);
        if (n <= 2) {
            return n;
        }
        memo[0] = 1;
        memo[1] = 2;
        for (int i = 2; i < n; ++i) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo[n - 1];
    }
};
