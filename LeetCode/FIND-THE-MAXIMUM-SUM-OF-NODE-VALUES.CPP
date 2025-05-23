#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, m, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    vector<vector<int>> e;
    for(int i = 0; i < n; i++) cin>>a[i];
    
    while(m--){
        int u, v;
        cin>>u>>v;
        e.push_back({u, v});
    }

    ll res = 0;
    int even = 0;
    ll minn = LLONG_MAX;

    for(int& x : a){
        ll t = x ^ k;
        res += max(t, (ll)x);

        if(t > x) even = 1 - even;
        
        minn = min(minn, abs(x - y));
    }
    cout<<res - n * minn;
    return 0;
}