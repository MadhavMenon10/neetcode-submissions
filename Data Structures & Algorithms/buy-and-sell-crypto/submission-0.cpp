class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int l = 0;
        int r = 1;
        while (r < prices.size()) {
            if (prices[r] > prices[l]) {
                int profit = -prices[l] + prices[r];
                max_profit = std::max(max_profit, profit);
            } else {
                l = r;
            }
            ++r;
        }
        return max_profit;
    }
};
