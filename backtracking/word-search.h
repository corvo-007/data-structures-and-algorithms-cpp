#include <vector>
#include <string>

namespace Backtracking {

    bool wordSearch(std::vector<std::vector<char>> &board, int row, int col, std::string word, int word_index) {
        if (word_index == word.length()) {
            return true;
        }

        if (row == -1 || row == board.size() || col == -1 || col == board[row].size() || board[row][col] != word[word_index] || board[row][col] == '\0') {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '\0';

        if (wordSearch(board, row - 1, col, word, word_index + 1) || wordSearch(board, row, col + 1, word, word_index + 1) || wordSearch(board, row + 1, col, word, word_index + 1) || wordSearch(board, row, col - 1, word, word_index + 1)) {
            board[row][col] = temp;
            return true;
        }

        board[row][col] = temp;
        return false;
    }

    bool wordSearch(std::vector<std::vector<char>> &board, std::string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && wordSearch(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}