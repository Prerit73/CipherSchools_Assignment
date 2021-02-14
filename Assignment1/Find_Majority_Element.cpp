#include <bits/stdc++.h>
using namespace std;

int check(vector<int> v){
    sort(v.begin(),v.end());
    int n=v.size();
    if(n%2==0){
        if((v[(n/2)-1]==v[n/2]) || (v[n/2]==v[(n/2)-1])){
             return v[v.size()/2];
        }
    }
    else{
        if((v[(n/2)+1]==v[n/2]) || (v[(n/2)-1]==v[(n/2)])){
             return v[v.size()/2];
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter size of array ";
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    int x=check(v);
    if(x==-1){
        cout<<"No majority element";
    }
    else{
        cout<<"element is "<<x;
    }

}

