#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 998244353

int n;
ll s, cnt = 0;

int main(){
    freopen(".\\txt\\DOOR.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    ll a[n + 1];
    unordered_map<ll, int> mp;
    mp[0] = 1;

    for(int i = 1; i<=n;i++) cin>>a[i];
    
    ll cur = 0;
    for(int i = 1; i<=n;i++){
        cur += a[i];
        cnt = (cnt + mp[cur - s]) % MOD;
        mp[cur]++;
    }

    cout<<cnt % MOD<<el;
    
    return 0;
}