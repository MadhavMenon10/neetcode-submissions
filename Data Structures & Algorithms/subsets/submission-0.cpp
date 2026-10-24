class Solution {
public:
    void backtrack(int i, std::vector<std::vector<int>>& answer, std::vector<int>& path, std::vector<int>& nums) {
        int n = nums.size();
        if (i == n) {
            answer.push_back(path);
            return;
        }
         path.push_back(nums[i]);
        backtrack(i+1, answer, path, nums);
        path.pop_back();
        backtrack(i+1, answer, path, nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::vector<int> path;
        backtrack(0, answer, path, nums);
        return answer;
    }
};
