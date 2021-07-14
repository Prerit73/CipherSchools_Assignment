#include <bits/stdc++.h>
using namespace std;

void generateParentheseHelper(int open , int close, string &resultSoFar, vector<string> &res){
    if (open < 0 || close < 0) {
        return;
    }
    if(open==0 && close==0){
        res.push_back(resultSoFar);
        return;
    }
    if(open>close){
        return;
    }else{
        resultSoFar.push_back('(');
        generateParentheseHelper(open-1,close,resultSoFar,res);
        resultSoFar.pop_back();
        
        resultSoFar.push_back(')');
        generateParentheseHelper(open,close-1,resultSoFar,res);
        resultSoFar.pop_back();
    }
}

vector<string> generateParenthese(int n){
    vector<string>res;
    string resultSoFar="";
    generateParentheseHelper(n,n,resultSoFar,res);
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<string>ans;
    ans=generateParenthese(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
