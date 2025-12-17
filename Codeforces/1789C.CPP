#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int tc = 1;

ll sol(){
    int n, m;
    cin>>n>>m;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    int t[n + 1] = {0};
    vector<map<int, int>> mp(n + 1);

    for(int i = 1; i <= m; i++){
        int pos, val;
        cin>>pos>>val;

        mp[pos][a[pos]] += i - t[pos];
        a[pos] = val;
        t[pos] = i;
    }

    for(int i = 1; i <= n; i++)
        mp[i][a[i]] += m - t[i] + 1;
    
    ll cnt[n + m + 1] = {0};
    for(int i = 1; i <= n; i++)
        for(auto x : mp[i])
            cnt[x.fi] += x.se;

    ll d = 0LL, res;
    for(int i = 1; i <= n + m; i++)
        d += cnt[i] * (m - cnt[i] + 1);

    res = 1LL * m * 1LL * (m + 1) / 2LL * n;
    return res + d / 2;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}