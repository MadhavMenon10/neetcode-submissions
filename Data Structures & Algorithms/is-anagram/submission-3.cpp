class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, int> map_s;
        std::unordered_map<char, int> map_t;
        for (unsigned int i = 0; i < s.size(); ++i) {
            if (map_s.count(s[i]) == 0) {
                map_s[s[i]] = 1;
            } else {
                ++map_s[s[i]];
            }
            if (map_t.count(t[i]) == 0) {
                map_t[t[i]] = 1;
            } else {
                ++map_t[t[i]];
            }
        }
        for (const auto& ch : s) {
            if (map_s[ch] != map_t[ch]) {
                return false;
            }
        }
        return true;
    }
};
