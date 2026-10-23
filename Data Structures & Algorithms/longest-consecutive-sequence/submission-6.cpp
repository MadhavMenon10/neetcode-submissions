class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> hash(nums.begin(), nums.end());
        int cnt = 0;
        for (auto num : nums) {
            if (hash.count(num - 1) != 0) {
                continue;
            }
            int curr = 1;
            while (hash.count(++num) != 0) {
                ++curr;
            }
            cnt = std::max(cnt, curr);
        }
        return cnt;
    }
};
