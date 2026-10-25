class Solution {
public:
    void mark(std::vector<std::vector<char>>& board, int i, int j) {
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        board[i][j] = '#';
        const std::vector<std::pair<int, int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (const auto& [dx, dy] : dirs) {
                int new_x = x + dx;
                int new_y = y + dy;
                if (0 <= new_x && new_x < board.size() && 0 <= new_y && new_y < board[0].size() && board[new_x][new_y] == 'O') {
                    board[new_x][new_y] = '#';
                    q.push({new_x, new_y});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O' && (i == 0  || i == board.size() - 1 || j == 0 || j == board[0].size() - 1)) {
                    mark(board, i, j);
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
