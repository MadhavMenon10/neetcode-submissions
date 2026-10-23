class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack_;
        stack_.push(0);
        for (const auto& c : tokens) {
            if (c == "+") {
                int num1 = stack_.top(); stack_.pop();
                int num2 = stack_.top(); stack_.pop();
                stack_.push(num1 + num2);
            } else if (c == "-") {
                int num1 = stack_.top(); stack_.pop();
                int num2 = stack_.top(); stack_.pop();
                stack_.push(num2 - num1);
            } else if (c == "*") {
                int num1 = stack_.top(); stack_.pop();
                int num2 = stack_.top(); stack_.pop();
                stack_.push(num1 * num2);
            } else if (c == "/") {
                int num1 = stack_.top(); stack_.pop();
                int num2 = stack_.top(); stack_.pop();
                stack_.push(num2 / num1);
            } else {
                stack_.push(std::stoi(c));
            }
        }
        return stack_.top();
    }
};
