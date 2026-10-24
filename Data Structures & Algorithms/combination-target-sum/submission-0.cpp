class Solution {
public:
// Either take the number until sum > target
// Not take the number
    void backtrack(int i, std::vector<int>& path, std::vector<std::vector<int>>& answer, std::vector<int>& nums, int target, int& sum) {

        int n = nums.size();
        if (sum == target) {
            answer.push_back(path);
            return;
        }
        if (i == n || sum > target) {
            return;
        }
        // Either take the number again
        path.push_back(nums[i]);
        sum += nums[i];
        backtrack(i, path, answer, nums, target, sum);
        path.pop_back();
        sum -= nums[i];


        // Do not take the number
        backtrack(i+1, path, answer, nums, target, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> answer;
        std::vector<int> path;
        int sum = 0;
        backtrack(0, path, answer, nums, target, sum);
        
        return answer;
    }
};
