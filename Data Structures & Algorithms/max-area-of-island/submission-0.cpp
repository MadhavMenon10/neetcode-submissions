class Solution {
public:
    int area(std::vector<std::vector<int>>& grid, int i, int j) {
        std::queue<std::pair<int, int>> q;
        int area = 1;
        grid[i][j] = 0;
        q.push({i, j});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x + 1 < grid.size() && grid[x + 1][y] != 0) {
                q.push({x + 1, y});
                ++area;
                grid[x + 1][y] = 0;
            }
            if (x - 1 >= 0 && grid[x - 1][y] != 0) {
                q.push({x - 1, y});
                ++area;
                grid[x - 1][y] = 0;
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] != 0) {
                q.push({x, y + 1});
                ++area;
                grid[x][y + 1] = 0;
            }
            if (y - 1 >= 0 && grid[x][y - 1] != 0) {
                q.push({x, y - 1});
                ++area;
                grid[x][y - 1] = 0;
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int island_area = area(grid, i, j);
                    max_area = std::max(max_area, island_area);
                }
            }
        }
        return max_area;
    }
};
