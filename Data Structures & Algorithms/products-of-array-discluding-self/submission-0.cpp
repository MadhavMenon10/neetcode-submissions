class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> answer(nums.size(), 1);
        std::vector<int> prefix(nums.size(), 1);
        std::vector<int> suffix(nums.size(), 1);
        prefix[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i - 1] * nums[i];
        }
        suffix[nums.size() - 1] = nums.back();
        for (int i = nums.size() - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i];
        }
        answer[0] = suffix[1];
        answer[nums.size() - 1] = prefix[nums.size() - 2];
        for (size_t i = 1; i < nums.size() - 1; ++i) {
            answer[i] = prefix[i - 1] * suffix[i + 1];
        }
        return answer;
    }
};