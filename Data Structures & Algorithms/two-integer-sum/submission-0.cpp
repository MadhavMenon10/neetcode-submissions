class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> map_;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (map_.count(diff) != 0) {
                result.push_back(i);
                result.push_back(map_[diff]);
                break;
            }
            map_[nums[i]] = i;
        }
        std::sort(result.begin(), result.end());
        return result;
    }
};
