#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
vector<int> res;

void sol(int x){
    res.push_back(x);

    for(int i = 0; i <= 9; i++){
        int t = x * 10 + i;
        if(t > n) return;
        
        sol(t);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i = 1; i <= min(n, 9); i++) sol(i);
    
    for(int t : res) cout<<t<<" ";
    return 0;
}