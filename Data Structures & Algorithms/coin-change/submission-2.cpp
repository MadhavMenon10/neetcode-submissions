class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> memo(amount + 1, amount + 1);
        memo[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            std::vector<int> options;
            for (int c : coins) {
                if (i - c >= 0) {
                    memo[i] = std::min(memo[i], 1 + memo[i - c]);
                }
            }
        }
        if (memo[amount] > amount) {
            return -1;
        }
        return memo[amount];
    }
};
