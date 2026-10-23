class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> res;
        std::unordered_map<int, int> map_;
        for (size_t i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (map_.contains(diff)) {
                if (i < map_[diff]) {
                    res.push_back(i);
                    res.push_back(map_[diff]);
                } else {
                    res.push_back(map_[diff]);
                    res.push_back(i);
                }
                break;
            }
            map_[nums[i]] = i;
        }
        return res;
    }
};
