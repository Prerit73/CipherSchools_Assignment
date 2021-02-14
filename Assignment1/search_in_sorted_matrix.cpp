#include <bits/stdc++.h>
using namespace std;

void isExist(vector<vector<int>> matrix,int target){
    
    int i=0,j=matrix[0].size();// took the top right element of matrix

    while(i<matrix.size() && j>=0){
        if(matrix[i][j]==target){
            break;
        }
        if(matrix[i][j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<"Element is found at "<<i<<","<<j<<endl;
}

int main(){
    vector<vector<int>> matrix={ {10, 20, 30, 40},{15, 25, 35, 45},{27, 29, 37, 48},{32, 33, 39, 50}};
    isExist(matrix,29);
}