/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

 

Constraints:

    board and word consists only of lowercase and uppercase English letters.
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3

*/

class Solution {
public:
    
    bool checker(vector<vector<char>>& board, string word, int index, int row, int col) {
        if (row < board.size() && row >= 0
            && col < board.at(0).size() && col >= 0) {
            if (index >= word.size() - 1) {
                return word.at(index) == board.at(row).at(col);
            }
            else if (word.at(index) == board.at(row).at(col)) {
                board.at(row).at(col) += 30;
                bool result = checker(board, word, index + 1, row, col - 1) 
                    || checker(board, word, index + 1, row, col + 1)
                    || checker(board, word, index + 1, row - 1, col)
                    || checker(board, word, index + 1, row + 1, col);
                board.at(row).at(col) -= 30;
                return result;
            }
            else return false;
        }
        else return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool result;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board.at(0).size(); col++) {
                if (board.at(row).at(col) == word.at(0)) {
                    result = checker(board, word, 0, row, col);
                    if (result) {
                        return true;
                    }
                }
            }
        }
        return result;
    }
};
