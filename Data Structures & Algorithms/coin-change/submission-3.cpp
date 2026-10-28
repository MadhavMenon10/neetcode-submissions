class Solution {
public:
// Coins: 1, 5, 10; amount = 12
// amount i i

    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> memo(amount + 1, INT_MAX);
        memo[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int c : coins) {
                if (i - c >= 0 && memo[i - c] != INT_MAX) {
                    memo[i] = std::min(memo[i], 1 + memo[i - c]);
                }
            }
        }
        if (memo[amount] == INT_MAX) {
            return -1;
        }
        return memo[amount];
    }
};
