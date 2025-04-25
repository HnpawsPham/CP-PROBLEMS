#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, MOD, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>MOD>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    unordered_map<int, int> mp;
    mp[0] = 1;
    int p = 0;
    ll res = 0;

    for(int r = 0; r < n; r++){
        p += (a[r] % MOD == k);

        res += mp[(p - k + MOD) % MOD];
        mp[p % MOD]++;
    }
    cout<<res;
    return 0;
}