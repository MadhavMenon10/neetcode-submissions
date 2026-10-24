class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::unordered_map<int, int> memo;
        memo[0] = 0;
        memo[1] = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            memo[i] = std::min(cost[i-1] + memo[i - 1], cost[i - 2] + memo[i - 2]);
        }
        return memo[cost.size()];
    }
};
