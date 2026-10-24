class Solution {
public:
    void backtrack(std::vector<std::vector<int>>& answer, std::vector<int>& path, std::vector<bool>& used, std::vector<int>& nums) {
        int n = nums.size();
        if (path.size() == n) {
           answer.push_back(path);
           return;
        }
        // Take the number
        for (int j = 0; j < n; ++j) {
            if (used[j]) {
                continue;
            }
            path.push_back(nums[j]);
            used[j] = true;
            backtrack(answer, path, used, nums);
            path.pop_back();
            used[j] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::vector<int> path;
        std::vector<bool> used(nums.size(), false);
        backtrack(answer, path, used, nums);
        return answer;
    }
};
