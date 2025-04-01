#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long;
#define el "\n"
#define pll pair<ll, ll>
#define fi first
#define se second

int n;
ll  u, v;
pll p[35];
vector<pll> gr1, gr2;

void sol1(ll i, ll a, ll b){
    if(i == n / 2){
        gr1.push_back({a, b});
        return;
    }

    sol1(i + 1, a + p[i].fi, b + p[i].se);
    sol1(i + 1, a, b);

    return;
}

void sol2(ll i, ll a, ll b){
    if(i == n){
        gr2.push_back({a, b});
        return;
    }

    sol2(i + 1, a + p[i].fi, b + p[i].se);
    sol2(i + 1, a, b);

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(ll i = 0; i < n; i++) 
        cin>>p[i].fi>>p[i].se;

    cin>>u>>v;
    sol1(0, 0, 0);
    sol2(n / 2, 0, 0);

    int res = 0;
    sort(gr2.begin(), gr2.end());

    for(pll x : gr1){
        pll target = {u - x.fi, v - x.se};
        res += upper_bound(gr2.begin(), gr2.end(), target) - lower_bound(gr2.begin(), gr2.end(), target);
    }

    cout<<res;
    return 0;
}