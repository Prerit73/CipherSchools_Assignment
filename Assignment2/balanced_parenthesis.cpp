#include <bits/stdc++.h>
using namespace std;

void balancedParenthesisHelper(vector<string>& result, int open, int close, int n, string str) {
    if (open < 0 || close < 0 || open > n || close > n || close > open) {
        return;
    }
    if (open == n && close == n) {
        result.push_back(str);
        return;
    }

    balancedParenthesisHelper(result, open + 1, close, n, str + "(");
    balancedParenthesisHelper(result, open, close + 1, n, str + ")");
}

vector<string> balancedParenthesis(int n) {
    vector<string> result;
    balancedParenthesisHelper(result, 0, 0, n, "");
    return result;
}
int main() {
    vector<string> result = balancedParenthesis(3);
    for (string res : result) {
        cout << res << endl;
    }

}