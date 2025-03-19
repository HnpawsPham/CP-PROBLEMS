#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first 
#define se second

int n, q;
const int maxn = 1e6 + 5;
int bit[maxn] = {};

void update(int i, int val){
    while(i < maxn){
        bit[i] += val;
        i += (i & -i);
    }
    return;
}

int get(int i){
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

int main(){
    freopen("DAY-LA-CO.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<ll> pos, quer;
    vector<pii> coor;

    for(int i = 0; i < n; i++){
        ll u, v;
        cin>>u>>v;
        coor.push_back({u, v});
        pos.push_back(u);
        pos.push_back(v);
    }
    cin>>q;
    while(q--){
        ll x; cin>>x;
        quer.push_back(x);
        pos.push_back(x);
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    map<ll, int> mp;
    int sz = pos.size();
    for(int i = 0; i < sz; i++) mp[pos[i]] = i + 1;

    for(pii x : coor){
        update(mp[x.fi], 1);
        update(mp[x.se] + 1, -1);
    }

    for(ll x : quer) cout<<get(mp[x])<<el; 
    return 0;
}