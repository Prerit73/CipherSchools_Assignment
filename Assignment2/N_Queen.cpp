#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<bool>> &board, int row, int col, int n)
{
    int r, c;
    for (c = 0; c < col; c++)
    {
        if (board[row][c])
            return false;
    }

    for (r = row, c = col; r >= 0 && c >= 0; r--, c--)
    {
        if (board[r][c])
            return false;
    }

    for (r = row, c = col; c >= 0 && r < n; r++, c--)
        if (board[r][c])
            return false;

    return true;
}

bool generateNQueenBoardHelper(vector<vector<bool>> &board, int col, int n)
{
    if (col >= n)
        return true;

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = true;
            if (generateNQueenBoardHelper(board, col + 1, n))
                return true;
            
            board[row][col] = false;
        }
    }

    return false;
}

bool generateNQueenBoard(int n)
{
    vector<vector<bool>> board(n, vector<bool>(n, false));
    if (!generateNQueenBoardHelper(board, 0, n))
    {
        return false;
    }
    else
    {
        for (vector<bool> row : board)
        {
            for (int cell : row)
            {
                if(cell==true){
                    cout<<1<<"  ";
                }
                else
                cout<<0<<"  ";
            }
            cout <<""<<endl;
        }
        return true;
    }
}

int main()
{
    generateNQueenBoard(4);
}
