class MinStack {
    public:
        MinStack() = default;
        
        void push(int val) {
            if (stack_.empty()) {
                stack_.push({val, val});
                return;
            }
            int curr_min = getMin();
            int new_min = std::min(val, curr_min);
            stack_.push({val, new_min});
        }
        
        void pop() {
            stack_.pop();
        }
        
        int top() {
            return stack_.top().first;
        }
        
        int getMin() {
            return stack_.top().second;
        }
    private:
        std::stack<std::pair<int, int>> stack_;
};
