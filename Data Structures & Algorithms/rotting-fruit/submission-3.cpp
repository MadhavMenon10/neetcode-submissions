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
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        int num_hit = 0;
        if (q.empty() && num_ones != 0) {
            return -1;
        }
        if (q.empty()) {
            return 0;
        }
        visited[q.front().first][q.front().second] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x + 1 < grid.size() && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
                    q.push({x + 1, y});
                    visited[x + 1][y] = true;
                    grid[x + 1][y] = 2;
                    ++num_hit;
                }
                if (x - 1 >= 0 && grid[x - 1][y] == 1 && !visited[x - 1][y]) {
                    q.push({x - 1, y});
                    visited[x - 1][y] = true;
                    grid[x - 1][y] = 2;
                    ++num_hit;
                }
                if (y + 1 < grid[0].size() && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
                    q.push({x, y + 1});
                    visited[x][y + 1] = true;
                    grid[x][y + 1] = 2;
                    ++num_hit;
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1 && !visited[x][y - 1]) {
                    q.push({x, y - 1});
                    visited[x][y - 1] = true;
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
