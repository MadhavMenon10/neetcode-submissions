class Solution {
public:
    bool is_valid(char c) {
        int pos = c - 'a';
        int capital_lower = 'A' - 'a';
        int capital_upper = 'Z' - 'a';
        int lower_lower = 'a' - 'a';
        int lower_upper = 'z' - 'a';
        int num_lower = '0' - 'a';
        int num_upper = '9' - 'a';
        return ((capital_lower <= pos && pos <= capital_upper) || (lower_lower <= pos && pos <= lower_upper) || (num_lower <= pos && pos <= num_upper));
    }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            while (l < r && !is_valid(s[l])) {
                ++l;
            }
            while (l < r && !is_valid(s[r])) {
                --r;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        
        return true;
    }
};
