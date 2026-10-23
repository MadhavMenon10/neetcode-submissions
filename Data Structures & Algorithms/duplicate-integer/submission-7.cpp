class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> map_;
        for (const auto& num : nums) {
            ++map_[num];
            if (map_[num] > 1) {
                return true;
            }
        }
        return false;
    }
};