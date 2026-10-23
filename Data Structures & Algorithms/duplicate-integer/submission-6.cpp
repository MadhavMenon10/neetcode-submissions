class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> map_;
        for (const auto& num : nums) {
            if (map_.count(num) == 0) {
                map_[num] = 1;
            } else {
                ++map_[num];
            }
            if (map_[num] > 1) {
                return true;
            }
        }
        return false;
    }
};