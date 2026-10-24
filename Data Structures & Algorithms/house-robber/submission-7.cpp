class Solution {
public:
    int rob(vector<int>& nums) {
       if (nums.size() == 1) {
            return nums[0];
       }
       if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
       }
       std::unordered_map<int, int> max_money;
       max_money[0] = nums[0];
       max_money[1] = std::max(nums[1], nums[0]);
       for (int i = 2; i < nums.size(); ++i) {
            max_money[i] = std::max(nums[i] + max_money[i - 2], max_money[i-1]);
       }
       return max_money[nums.size() - 1];

    }
};
