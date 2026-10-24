class Solution {
public:
    void backtrack(int i, std::set<std::vector<int>>& seen, std::vector<int>& path, std::vector<int>& nums) {

        int n = nums.size();
        if (i == n) {
            seen.insert(path);
            return;
        }
        // Don't take num
        backtrack(i + 1, seen, path, nums);
        // Take num
        path.push_back(nums[i]);
        backtrack(i + 1, seen, path, nums);
        path.pop_back();


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::set<std::vector<int>> seen;
        std::vector<int> path;
        std::sort(nums.begin(), nums.end());
        backtrack(0, seen, path, nums);
        std::vector<std::vector<int>> answer(seen.begin(), seen.end());
        return answer;

    }
};
