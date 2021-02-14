#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    vector<int> newarray;

    if (matrix.size() == 0)
        return newarray;

    int start_row = 0, end_row = matrix.size() - 1, start_col = 0, end_col = matrix[0].size() - 1;

    while (start_row <= end_row && start_col <= end_col)
    {
        for (int col = start_col; col <= end_col; col++)
            newarray.push_back(matrix[start_row][col]);
        start_row++;

        for (int row = start_row; row <= end_row; row++)
            newarray.push_back(matrix[row][end_col]);
        end_col--;

        if (start_row <= end_row)
        {
            for (int col = end_col; col >= start_col; col--)
                newarray.push_back(matrix[end_row][col]);
            end_row--;
        }

        if (start_col <= end_col)
        {
            for (int row = end_row; row >= start_row; row--)
                newarray.push_back(matrix[row][start_col]);
            start_col++;
        }
    }
    return newarray;
}

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans=spiralOrder(matrix);
    for(int i: ans){
        cout<<i<<" ";
    }
}