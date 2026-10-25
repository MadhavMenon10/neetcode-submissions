class Solution {
public:
    void bfs(std::vector<std::vector<char>>& grid, int i, int j) {
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x - 1 >= 0) {
                if (grid[x-1][y] != '0') {
                    q.push({x-1, y});
                    grid[x-1][y] = '0';
                }
            }
            if (x + 1 < grid.size()) {
                if (grid[x+1][y] != '0') {
                    q.push({x+1, y});
                    grid[x+1][y] = '0';
                }
            }
            if (y + 1 < grid[0].size()) {
                if (grid[x][y + 1] != '0') {
                    q.push({x, y+1});
                    grid[x][y+1] = '0';
                }
            }
            if (y - 1 >= 0) {
                if (grid[x][y-1] != '0') {
                    q.push({x, y-1});
                    grid[x][y-1] = '0';
                }
            }
        }
    } 
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++num_islands;
                }
            }
        }
        return num_islands;
    }
};
