class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack_;
        for (const auto& c : s) {
            if (c == '{' || c == '(' || c == '[') {
                stack_.push(c);
            } else {
                if (stack_.empty()) {
                    return false;
                }
                if (c == '}' && stack_.top() == '{') {
                    stack_.pop();
                } else if (c == ')' && stack_.top() == '(') {
                    stack_.pop();
                } else if (c == ']' && stack_.top() == '[') {
                    stack_.pop();
                } else {
                    return false;
                }
            }
        }
        return stack_.empty();
    }
};
