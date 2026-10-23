class Solution {
public:
    std::vector<int> get_ctr(const std::string& word) {
        std::vector<int> count(26, 0);
        for (const auto& c : word) {
            ++count[c - 'a'];
        }
        return count;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::vector<int>, std::vector<std::string>> anagram_map;
        std::vector<std::vector<std::string>> answer;
        for (const auto& word : strs) {
            anagram_map[get_ctr(word)].push_back(word);
        }
        for (const auto& [key, val] : anagram_map) {
            answer.push_back(val);
        }
        return answer;
    }
};
