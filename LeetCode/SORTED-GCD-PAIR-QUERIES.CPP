#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define fi first
#define se second
//#define taskname ""

const int maxn = 5e4 + 5;
int cnt[maxn];
ll g[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    int q[m];
    for(int i = 0; i < m; i++) cin>>q[i];

    memset(cnt, 0, sizeof cnt);
    memset(g, 0, sizeof g);
    for(const int& x : a) cnt[x]++;

    int lim = *max_element(a.begin(), a.end());
    for(int i = lim; i > 0; i--){
        ll cntmul = 0;
        for(int j = i; j <= lim; j+=i)
            cntmul += cnt[j];

        g[i] = cntmul * (cntmul - 1) / 2;
    }

    for(int i = lim; i > 0; i--)
      for(int j = i + i; j <= lim; j+=i)
            g[i] -= g[j];

    ll sum = 0;
    vector<pli> mp;
    for(int i = 1; i <= lim; i++)
        if(g[i]){
            sum += g[i];
            mp.push_back({sum, i});
        }

    vector<int> res;
    int sz = mp.size();

    for(int x : q){
        x++;
        int l = 0, r = sz - 1, mid, pos = 0;
        while(l <= r){
            mid = (l + r) / 2;

            if(mp[mid].fi >= x){
                r = mid - 1;
                pos = mid;
            }
            else l = mid + 1;
        }
        res.push_back(mp[pos].se);
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 3 3
// 2 3 4
// 0 2 2