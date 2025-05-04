#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>
#define se second

int n, u, v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<vi> a(n);
    for(int i = 0; i < n; i++){
        cin>>u>>v;
        a[i] = {u, v};
    }

    map<vi, int> mp;
    for(const vi &v : a) 
        mp[{max(v[0], v[1]), min(v[0], v[1])}]++;
    
    int res = 0;
    for(auto x : mp)
        res += x.se * (x.se - 1) / 2;
    cout<<res;
    return 0;
}