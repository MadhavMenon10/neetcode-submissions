class Solution {
public:
    void backtrack(int i, std::vector<int>& path, std::set<std::vector<int>>& answer, std::vector<int>& candidates, int target, int sum) {
        int n = candidates.size();
        if (sum == target) {
            answer.insert(path);
            return;
        }
        if (sum > target || i == n) {
            return;
        }

        // Either take the number at pos i
        path.push_back(candidates[i]);
        backtrack(i+1, path, answer, candidates, target, sum + candidates[i]);
        path.pop_back();
        // Skip
        while (i + 1 < n && candidates[i] == candidates[i+1]) {
            ++i;
        }
        backtrack(i+1, path, answer, candidates, target, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::set<std::vector<int>> answer;
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> path;
        backtrack(0, path, answer, candidates, target, 0);
        std::vector<std::vector<int>> answer_vect(answer.begin(), answer.end());
        return answer_vect;
    }
};
