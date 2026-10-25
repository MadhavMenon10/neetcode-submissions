class Solution {
public:
    std::unordered_map<int, std::vector<int>> build_adj_list(const std::vector<std::vector<int>>& prereqs) {
        std::unordered_map<int, std::vector<int>> adj_list;
        for (const auto& prereq : prereqs) {
            adj_list[prereq[0]].push_back(prereq[1]);
        }
        return adj_list;
    }

    bool has_cycle(int node, const std::unordered_map<int, std::vector<int>>& adj_list, std::vector<int>& state) {
        state[node] = 1;
        auto it = adj_list.find(node);
        if (it == adj_list.end()) {
            state[node] = 2;
            return false;
        }
        for (const auto& adj_node : it->second) {
            if (state[adj_node] == 0) {
                if (has_cycle(adj_node, adj_list, state)) {
                    return true;
                }
            } else if (state[adj_node] == 1) {
                return true;
            }
        }
        state[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> adj_list = build_adj_list(prerequisites);
        std::vector<int> state(numCourses, 0);
        // 0: unvisited, 1: visiting, 2: visited
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (has_cycle(i, adj_list, state)) {
                    return false;
                }
            } 
        }
        return true;
    }
};
