class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (auto& num : nums) {
            ++freq[num];
        }
        std::vector<int> res;
        int max_val = 0;
        std::vector<std::vector<int>> answer(nums.size() + 1);
        for (auto& [key, val] : freq) {
            answer[val].push_back(key);
            if (val > max_val) {
                max_val = val;
            }
        }
        int n = 0;
        for (int i = nums.size(); i >= 0; --i) {
            if (answer[i].empty()) {
                continue;
            } 
            for (const auto& num : answer[i]) {
                res.push_back(num);
                ++n;
                if (n == k) {
                    break;
                }
            }
            if (n == k) {
                break;
            }
        }

        return res;
    }
};
