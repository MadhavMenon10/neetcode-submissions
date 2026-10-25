class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min_minutes = 0;
        bool contains_fresh = false;
        int i = 0; int j = 0;
        int num_ones = 0;
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    ++num_ones;
                }
            }
        }
        int num_hit = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
                    q.push({x + 1, y});
                    grid[x + 1][y] = 2;
                    ++num_hit;
                }
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    q.push({x - 1, y});
                    grid[x - 1][y] = 2;
                    ++num_hit;
                }
                if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
                    q.push({x, y + 1});
                    grid[x][y + 1] = 2;
                    ++num_hit;
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    q.push({x, y - 1});
                    grid[x][y - 1] = 2;
                    ++num_hit;
                }
            }
            if (q.empty()) {
                break;
            } else {
                ++min_minutes;
            }
        }
        if (num_hit != num_ones) {
            return -1;
        }
        return min_minutes;
    }
};
