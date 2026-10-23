class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<int> indices;
        indices.push(0);
        for (int i = 0; i < temperatures.size() - 1; ++i) {
            if (temperatures[i+1] > temperatures[i]) {
                while (!indices.empty() && temperatures[i + 1] > temperatures[indices.top()]) {
                    result[indices.top()] = i + 1 - indices.top();
                    indices.pop();
                }
            } 
            indices.push(i+1);
        }
        return result;
    }
};
