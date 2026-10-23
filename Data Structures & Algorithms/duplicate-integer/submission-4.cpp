#include <set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> set_nums;
        for (const auto& num : nums) {
            set_nums.insert(num);
        }
        return set_nums.size() != nums.size();
    }
};
