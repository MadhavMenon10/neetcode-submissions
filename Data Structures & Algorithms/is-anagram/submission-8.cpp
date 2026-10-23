class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;
        for (size_t i = 0; i < s.length(); ++i) {
            ++s_map[s[i]];
            ++t_map[t[i]];
        }      
        for (size_t i = 0; i < s.length(); ++i) {
            if (s_map[s[i]] != t_map[s[i]]) {
                return false;
            }
        }
        return true;
    }
};
