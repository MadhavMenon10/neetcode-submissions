class Solution {
public:
    int dist(const std::vector<int>& coords) {
        int x = coords[0];
        int y = coords[1];
        return x * x + y * y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<
            std::pair<int, std::vector<int>>,
            std::vector<std::pair<int, std::vector<int>>>,
            std::greater<std::pair<int, std::vector<int>>>
            > pq;
        for (const auto& coord : points) {
            pq.push({dist(coord), coord});
        }
        std::vector<std::vector<int>> closest_points;
        for (int i = 0; i < k; ++i) {
            closest_points.push_back(pq.top().second);
            pq.pop();
        }
        return closest_points;

    }
};
