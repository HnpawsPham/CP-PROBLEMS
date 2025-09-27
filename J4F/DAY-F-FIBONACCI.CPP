#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const ll MOD = 1e9 + 7;

int main(){
    // freopen("DF.INP", "r", stdin);
    // freopen("DF.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    int x, y;
    cin>>x>>y;

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];
 
    ll f0 = x, f1 = y;
    unordered_set<ll> s;
    vector<ll> fibo = {x};
    if(y != x) fibo.push_back(y);

    while(f1 <= p[n]){
        ll tmp = f0 + f1;
        f0 = f1;
        f1 = tmp;
        if(!s.count(tmp)){
            fibo.push_back(f1);
            s.insert(f1);
        }
    }

    ll dp[n + 1] = {0};
    unordered_map<ll, int> mp;
    dp[0] = mp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(ll x : fibo){
            if(mp.count(p[i] - x))
                dp[i] = (dp[i] + mp[p[i] - x]) % MOD;
        }
        mp[p[i]] = dp[i];
    }
    cout<<dp[n];
    return 0;
}

// 6
// 1 3 2 2 1 4
// 1 1