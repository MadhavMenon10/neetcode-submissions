#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> my_set;
        for (const auto& num : nums) {
            my_set.insert(num);
        }
        if (my_set.size() == nums.size()) {
            return false;
        } else {
            return true;
        }
    }
};
