#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pll pair<ll, ll>
#define fi first
#define se second

int n;
ll m;
const int maxn = 45;
pll a[maxn];
vector<pll> g1, g2;

void sol1(int i, ll sum, ll val){
    if(sum > m) return;

    if(i == n / 2){
        g1.push_back({sum, val});
        return;
    }

    sol1(i + 1, sum, val);
    sol1(i + 1, sum + a[i].fi, val + a[i].se);
    return;
}

void sol2(int i, ll sum, ll val){
    if(sum > m) return;

    if(i == n){
        g2.push_back({sum, val});
        return;
    }

    sol2(i + 1, sum, val);
    sol2(i + 1, sum + a[i].fi, val + a[i].se);
    return;
}

bool comp(pll a, pll b){
    return a.fi < b.fi;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;

    sol1(0, 0, 0);
    sol2(n / 2, 0, 0);

    ll maxx = -1;
    int sz = g2.size();
    sort(g2.begin(), g2.end());

    ll maxval[sz];
    if(sz > 0) maxval[0] = g2[0].se;
    for(int i = 1; i < n; i++) maxval[i] = max(maxval[i - 1], g2[i].se);

    for(pll x : g1){
        ll sum = x.fi;
        ll val = x.se;

        int pos = upper_bound(g2.begin(), g2.end(), make_pair(m - sum, LLONG_MIN)) - g2.begin();

        if(pos > 0) maxx = max(maxx, maxval[pos - 1]);
    }
    cout<<maxx;

    return 0;
}