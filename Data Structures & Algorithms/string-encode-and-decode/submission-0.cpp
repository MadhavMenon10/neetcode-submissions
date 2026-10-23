class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encoded_string {};
        for (const auto& str : strs) {
            std::string encode_str;
            for (const auto& c : str) {
                encode_str += c - 'a';
            }
            encoded_string += encode_str;
            encoded_string += '_';
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        std::vector<std::string> decoded_string;
        std::string word;
        for (const auto& c : s) {
            if (c == '_') {
                decoded_string.push_back(word);
                word = "";
                continue;
            } else {
                word += c + 'a';
            }
        }
        return decoded_string;
    }
};
