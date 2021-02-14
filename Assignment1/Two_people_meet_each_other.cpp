#include<bits/stdc++.h>
using namespace std;

bool check(int d1,int v1,int d2,int v2){
    if(d1<d2 && v1<=v2){
        return false;
    }
    if(d1>d2 && v1>=v2){
        return false;
    }

    int D=d1-d2;
    int S=v1-v2;
    if(D<0){
        D*=-1;
    }
    if(S<0){
        S*=-1;
    }
    return (D%S==0);
}

int main(){
    int d1,d2,v1,v2;
    // first give d1,v1 and then d2,v2
    cin>>d1>>v1>>d2>>v2;
    if(check(d1,v1,d2,v2)){
        cout<<"They will meet";
    }
    else
    cout<<"They will not meet";
}