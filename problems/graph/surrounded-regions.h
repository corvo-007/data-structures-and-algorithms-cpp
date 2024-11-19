#include <vector>

namespace Graph {

    void dfs(std::vector<std::vector<char>> &board, int i, int j) {
        if (board[i][j] == 'X' || board[i][j] == 'A') {
            return;
        }

        board[i][j] = 'A';

        if (i - 1 >= 0) {
            dfs(board, i - 1, j);
        }
        if (j + 1 < board[0].size()) {
            dfs(board, i, j + 1);
        }
        if (i + 1 < board.size()) {
            dfs(board, i + 1, j);
        }
        if (j - 1 >= 0) {
            dfs(board, i, j - 1);
        }
    }

    void surroundedRegions(std::vector<std::vector<char>> &board) {

        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }

            if (board[i][board[0].size() - 1] == 'O') {
                dfs(board, i, board[0].size() - 1);
            }
        }

        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }

            if (board[board.size() - 1][i] == 'O') {
                dfs(board, board.size() - 1, i);
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
    }
}
