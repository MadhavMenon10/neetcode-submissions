class Solution {
public:
    std::unordered_map<int, std::vector<int>> build_adj_list(const std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> adj_list;
        for (const auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        return adj_list;
    }
    bool has_cycle(int i, std::vector<int>& state, std::unordered_map<int, std::vector<int>>& adj_list) {
        state[i] = 1;
        auto it = adj_list.find(i);
        if (it == adj_list.end()) {
            state[i] = 2;
            return false;
        }
        for (const auto& node : it->second) {
            if (state[node] == 0) {
                if (has_cycle(node, state, adj_list)) {
                    return true;
                }
            } else if (state[node] == 2) {
                return true;
            }
        }
        state[i] = 2;
        return false;
    }  

    bool validTree(int n, vector<vector<int>>& edges) {
        int num_dfs = 0;
        auto adj_list = build_adj_list(edges);
        std::vector<int> state(n, 0);
        for (int i = 0; i < n; ++i) {
            if (state[i] == 0) {
                ++num_dfs;
                if (has_cycle(i, state, adj_list)) {
                    return false;
                }
            }
        }
        if (num_dfs > 1) {
            return false;
        }
        return true;
    }

};
