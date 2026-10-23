class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; 
        int r = 0;
        int max_length = 0;
        std::unordered_set<char> chars;
        while (r < s.length()) {
            if (chars.count(s[r])) {
                while (chars.count(s[r]) != 0) {
                    chars.erase(s[l]);
                    ++l;
                }
            } else {
                chars.insert(s[r]);
                ++r;
                max_length = std::max(max_length, r - l);
            }
        }
        return max_length;
    }
};
