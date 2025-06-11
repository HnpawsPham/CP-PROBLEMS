#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, k;
vector<vi> res;

void sol(int i, int cur, vi& v){
    if(i == k){
        res.push_back(v);
        return;
    }

    for(int j = cur; j <= n; j++){
        v.push_back(j);
        sol(i + 1, j + 1, v);
        v.pop_back();
    }

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vi v;
    sol(0, 1, v);

    for(const vi& v : res){
        for(int x : v) cout<<x<<" ";
        cout<<el;
    }
    return 0;
}