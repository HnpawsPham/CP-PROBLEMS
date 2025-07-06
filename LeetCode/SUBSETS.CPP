#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
vector<vector<int>> res;

void sol(int i, vector<int>& v, vector<int>& a){
    res.push_back(v);
    if(i == n) return;

    for(int j = i; j < n; j++){
        v.push_back(a[j]);
        sol(j + 1, v, a);
        v.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<int> tmp;
    sol(0, tmp, a);

    for(auto v : res){
        for(auto x : v) cout<<x<<" ";
        cout<<el;
    }
    return 0;
}