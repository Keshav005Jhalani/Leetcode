class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int i, int j, char digit) {
        for (int k = 0; k < 9; k++) {
            if (board[k][j] == digit) return false;
            if (board[i][k] == digit) return false;
            if (board[3*(i/3) + k/3][3*(j/3) + k%3] == digit) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isSafe(board, i, j, digit)) {
                            board[i][j] = digit;
                            if (solve(board)==true) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
