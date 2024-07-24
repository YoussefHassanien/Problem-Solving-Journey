#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> columns;
    unordered_set<char> rows;
    unordered_set<char> box;

    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            if (rows.find(board[i][j]) != rows.end() || columns.find(board[j][i]) != columns.end())
                return false;
            if (board[i][j] != '.')
                rows.emplace(board[i][j]);
            if (board[j][i] != '.')
                columns.emplace(board[j][i]);
        }
        rows.clear();
        columns.clear();
    }

    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if (box.find(board[k + i][l + j]) != box.end())
                        return false;
                    if (board[k + i][l + j] != '.')
                        box.emplace(board[k + i][l + j]);
                }
            }
            box.clear();
        }
    }

    return true;

    //unordered_map<int, unordered_set<char>> cols;
    //unordered_map<int, unordered_set<char>> rows;
    //unordered_map<int, unordered_set<char>> squares;  // key = (r / 3) * 3 + c / 3

    //for (int r = 0; r < 9; r++) {
    //    for (int c = 0; c < 9; c++) {
    //        char cell = board[r][c];
    //        if (cell == '.') {
    //            continue;
    //        }
    //        if (rows[r].count(cell) || cols[c].count(cell) || squares[(r / 3) * 3 + c / 3].count(cell)) {
    //            return false;
    //        }
    //        cols[c].insert(cell);
    //        rows[r].insert(cell);
    //        squares[(r / 3) * 3 + c / 3].insert(cell);
    //    }
    //}
    //return true;
}

void main()
{
    vector<vector<char>> board = {
        {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (isValidSudoku(board))
        cout << "True";
    else cout << "False";
}