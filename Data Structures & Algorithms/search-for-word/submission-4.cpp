class Solution {
public:
    void backtrack(std::vector<std::vector<char>>& board, std::string& curr, bool& answer, int i, int j, std::string& word) {
        if (curr.length() >= word.length() && curr == word) {
            answer = true;
            return;
        } else if (curr.length() >= word.length()) {
            return;
        } 
        if (board[i][j] == '#') {
            return;
        }
        // Go left
        char saved = board[i][j];
        board[i][j] = '#';
        if (i - 1 >= 0) {
            curr += board[i - 1][j];
            backtrack(board, curr, answer, i-1, j, word);
            curr.pop_back();
        }
        if (i + 1 < board.size()) {
            curr += board[i + 1][j];
            backtrack(board, curr, answer, i + 1, j, word);
            curr.pop_back();
        }
        // Go right
        
        // Go down
        if (j + 1 < board[0].size()) {
            curr += board[i][j + 1];
            backtrack(board, curr, answer, i, j + 1, word);
            curr.pop_back();
        }
        
        // Go up
        if (j - 1 >= 0) {
            curr += board[i][j - 1];
            backtrack(board, curr, answer, i, j - 1, word);
            curr.pop_back();
        }
        board[i][j] = saved;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if (word.length() > m * n) {
            return false;
        }
        bool answer = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    std::string start(1, word[0]);
                    backtrack(board, start, answer, i, j, word);
                    if (answer) {
                        break;
                    }
                }
            }
        }
        return answer;

    }
};
