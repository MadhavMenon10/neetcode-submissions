class Solution {
public:
    void backtrack(int i, std::vector<std::string>& answer, std::string& path, std::string digits, std::unordered_map<char, std::vector<char>>& map_, std::vector<bool>& used) {
        if (path.length() == digits.length()) {
            answer.push_back(path);
            return;
        }
        if (i >= digits.length()) {
            return;
        }

        for (int j = 0; j < map_[digits[i]].size(); ++j) {
            // if (used[map_[digits[i]][j] - 'a']) {
            //     continue;
            // }
            path += map_[digits[i]][j];
            // used[map_[digits[i]][j] - 'a'] = true;
            backtrack(i + 1, answer, path, digits, map_, used);
            path.pop_back();
            // used[map_[digits[i]][j] - 'a'] = false;
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        std::unordered_map<char, std::vector<char>> map_ {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        std::string path;
        std::vector<std::string> answer;
        std::vector<bool> used(26, false);
        backtrack(0, answer, path, digits, map_, used);
        return answer;
        

    }
};
