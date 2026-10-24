class Solution {
public:
    int rob(vector<int>& nums) {
        std::unordered_map<int, int> memo;
        memo[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (i == 1) {
                memo[i] = nums[1];
            }
            if (i == 2) {
                memo[i] = std::max(memo[1], memo[0] + nums[2]);
            }
            memo[i] = std::max(nums[i] +  std::max(memo[i-2], memo[i-3]), memo[i-1]);
        }
        return memo[nums.size() - 1];

    }
};
