class Solution {
public:
    std::unordered_map<int, std::vector<int>> build_adjacency_list(const std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> adj_list;
        for (const auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        return adj_list;
    }
    void bfs(int node_val, const std::unordered_map<int, std::vector<int>>& graph, std::unordered_set<int>& visited) {
        visited.insert(node_val);
        std::queue<int> q;
        q.push(node_val);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            auto it = graph.find(curr);
            if (it == graph.end()) {
                continue;
            }
            for (const int neighbor : it->second) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int num_components = 0;
        auto adj_list = build_adjacency_list(edges);
        std::unordered_set<int> visited;
        for (int i = 0; i < n; ++i) {
            if (!visited.count(i)) {
                 bfs(i, adj_list, visited);
                ++num_components;
            }
        }
        return num_components;
    }
};
