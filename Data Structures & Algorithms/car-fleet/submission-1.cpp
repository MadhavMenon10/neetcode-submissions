class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        std::unordered_map<int, int> speed_map;
        for (int i = 0; i < n; ++i) {
            speed_map[position[i]] = speed[i];
        }
        std::sort(position.begin(), position.end(), greater<int>());
        std::stack<double> stack_;
        double init_time = static_cast<double>((target-position[0]))/speed_map[position[0]];
        stack_.push(init_time);
        for (int i = 1; i < n; ++i) {
            double time = static_cast<double>((target - position[i])) / speed_map[position[i]];
            if (time <= stack_.top()) {
                continue;
            } else {
                stack_.push(time);
            }
        }
        return stack_.size();
    }
        
};
